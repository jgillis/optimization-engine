import yaml
import os
import subprocess
import socket
import json
from threading import Thread
from retry import retry


class OptimizerTcpManager:
    """Client for TCP interface of parametric optimizers

    This class is used to start and stop a TCP server, which
    has been generated by <code>opengen</code>.
    """

    def __init__(self, optimizer_path):
        """Constructs instance of <code>OptimizerTcpManager</code>

        Args:
            optimizer_path: path to auto-generated optimizer (just to
            be clear: this is the folder that contains <code>optimizer.yml</code>)

        Returns:
            New instance of <code>OptimizerTcpManager</code>
        """
        self.__optimizer_path = optimizer_path
        self.__optimizer_details_from_yml = None
        self.__load_tcp_details()

    def __load_tcp_details(self):
        yaml_file = os.path.join(self.__optimizer_path, "optimizer.yml")
        with open(yaml_file, 'r') as stream:
            self.__optimizer_details_from_yml = yaml.safe_load(stream)

    def __threaded_start(self):
        optimizer_details = self.__optimizer_details_from_yml
        command = ['cargo', 'run']
        if optimizer_details['build']['build_mode'] == 'release':
            command.append('--release')
        p = subprocess.Popen(command, cwd=self.__optimizer_path)
        p.wait()

    @retry(tries=10, delay=1)
    def __obtain_socket_connection(self):
        tcp_data = self.__optimizer_details_from_yml
        ip = tcp_data['tcp']['ip']
        port = tcp_data['tcp']['port']
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
        s.connect((ip, port))
        return s

    def __send_receive_data(self, text_to_send, buffer_size=512):
        conn_socket = self.__obtain_socket_connection()
        encoded_data = text_to_send.encode()
        conn_socket.sendall(encoded_data)
        conn_socket.shutdown(socket.SHUT_WR)
        for _i in range(100):
            data = conn_socket.recv(buffer_size)
            if data is not None:
                break
        conn_socket.close()
        return data.decode()

    def ping(self):
        """Pings the server

        Pings the server to check whether it is up and running
        """
        request = '{"Ping":1}'
        data = self.__send_receive_data(request)
        return json.loads(data)

    def start(self):
        """Starts the TCP server"""
        # TODO: start only if the server has not started
        # start the server in a separate thread
        thread = Thread(target=self.__threaded_start)
        thread.start()

        # ping the server until it responds so that we know it's
        # up and running
        self.ping()

    def kill(self):
        """Kills the server"""
        request = '{"Kill":1}'
        self.__send_receive_data(request)

    def call(self, p, initial_guess=None, buffer_len=4096):
        """Calls the server

        Consumes the parametric optimizer by providing a parameter vector
        and, optionally, an initial guess

        Args:
             p: vector of parameters (vector of float)
             initial_guess: initial guess vector (vector of float)
             buffer_len: buffer length used to read the server response
             (default value: 4096)

        Returns:
            Dictionary with the following keys:
                exit_status: exit status (string)
                num_outer_iterations: number of outer iterations
                num_inner_iterations: total number of inner iterations
                last_problem_norm_fpr: norm of FPR of last inner problem
                max_constraint_violation:  inf-norm of c(u; p)
                solve_time_ms: solve time in ms
                solution: solution vector

        """
        # Make request
        run_message = '{"Run" : {"parameter": ['
        run_message += ','.join(map(str, p))
        run_message += ']'

        if initial_guess is not None:
            run_message += ', "initial_guess": ['
            run_message += ','.join(map(str, initial_guess))
            run_message += ']'

        run_message += '}}'
        data = self.__send_receive_data(run_message, buffer_len)
        return json.loads(data)
