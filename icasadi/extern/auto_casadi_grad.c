/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CODEGEN_PREFIX
  #define NAMESPACE_CONCAT(NS, ID) _NAMESPACE_CONCAT(NS, ID)
  #define _NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) auto_casadi_grad_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int long long int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_sq CASADI_PREFIX(sq)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

static const casadi_int casadi_s0[14] = {10, 1, 0, 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
static const casadi_int casadi_s1[6] = {2, 1, 0, 2, 0, 1};
static const casadi_int casadi_s2[23] = {1, 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

casadi_real casadi_sq(casadi_real x) { return x*x;}

/* grad_phi:(i0[10],i1[2])->(o0[1x10]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, void* mem) {
  casadi_real a0, a1, a2, a3, a4, a5;
  a0=arg[1] ? arg[1][0] : 0;
  a0=casadi_sq(a0);
  a1=arg[1] ? arg[1][1] : 0;
  a1=casadi_sq(a1);
  a0=(a0+a1);
  a1=arg[0] ? arg[0][0] : 0;
  a2=cos(a1);
  a3=casadi_sq(a2);
  a4=cos(a3);
  a4=(a0*a4);
  a5=sin(a1);
  a2=(a2+a2);
  a3=sin(a3);
  a1=(a0*a1);
  a3=(a3*a1);
  a2=(a2*a3);
  a5=(a5*a2);
  a4=(a4+a5);
  if (res[0]!=0) res[0][0]=a4;
  a4=arg[0] ? arg[0][1] : 0;
  a5=cos(a4);
  a2=casadi_sq(a5);
  a3=cos(a2);
  a3=(a0*a3);
  a1=sin(a4);
  a5=(a5+a5);
  a2=sin(a2);
  a4=(a0*a4);
  a2=(a2*a4);
  a5=(a5*a2);
  a1=(a1*a5);
  a3=(a3+a1);
  if (res[0]!=0) res[0][1]=a3;
  a3=arg[0] ? arg[0][2] : 0;
  a1=cos(a3);
  a5=casadi_sq(a1);
  a2=cos(a5);
  a2=(a0*a2);
  a4=sin(a3);
  a1=(a1+a1);
  a5=sin(a5);
  a3=(a0*a3);
  a5=(a5*a3);
  a1=(a1*a5);
  a4=(a4*a1);
  a2=(a2+a4);
  if (res[0]!=0) res[0][2]=a2;
  a2=arg[0] ? arg[0][3] : 0;
  a4=cos(a2);
  a1=casadi_sq(a4);
  a5=cos(a1);
  a5=(a0*a5);
  a3=sin(a2);
  a4=(a4+a4);
  a1=sin(a1);
  a2=(a0*a2);
  a1=(a1*a2);
  a4=(a4*a1);
  a3=(a3*a4);
  a5=(a5+a3);
  if (res[0]!=0) res[0][3]=a5;
  a5=arg[0] ? arg[0][4] : 0;
  a3=cos(a5);
  a4=casadi_sq(a3);
  a1=cos(a4);
  a1=(a0*a1);
  a2=sin(a5);
  a3=(a3+a3);
  a4=sin(a4);
  a5=(a0*a5);
  a4=(a4*a5);
  a3=(a3*a4);
  a2=(a2*a3);
  a1=(a1+a2);
  if (res[0]!=0) res[0][4]=a1;
  a1=arg[0] ? arg[0][5] : 0;
  a2=cos(a1);
  a3=casadi_sq(a2);
  a4=cos(a3);
  a4=(a0*a4);
  a5=sin(a1);
  a2=(a2+a2);
  a3=sin(a3);
  a1=(a0*a1);
  a3=(a3*a1);
  a2=(a2*a3);
  a5=(a5*a2);
  a4=(a4+a5);
  if (res[0]!=0) res[0][5]=a4;
  a4=arg[0] ? arg[0][6] : 0;
  a5=cos(a4);
  a2=casadi_sq(a5);
  a3=cos(a2);
  a3=(a0*a3);
  a1=sin(a4);
  a5=(a5+a5);
  a2=sin(a2);
  a4=(a0*a4);
  a2=(a2*a4);
  a5=(a5*a2);
  a1=(a1*a5);
  a3=(a3+a1);
  if (res[0]!=0) res[0][6]=a3;
  a3=arg[0] ? arg[0][7] : 0;
  a1=cos(a3);
  a5=casadi_sq(a1);
  a2=cos(a5);
  a2=(a0*a2);
  a4=sin(a3);
  a1=(a1+a1);
  a5=sin(a5);
  a3=(a0*a3);
  a5=(a5*a3);
  a1=(a1*a5);
  a4=(a4*a1);
  a2=(a2+a4);
  if (res[0]!=0) res[0][7]=a2;
  a2=arg[0] ? arg[0][8] : 0;
  a4=cos(a2);
  a1=casadi_sq(a4);
  a5=cos(a1);
  a5=(a0*a5);
  a3=sin(a2);
  a4=(a4+a4);
  a1=sin(a1);
  a2=(a0*a2);
  a1=(a1*a2);
  a4=(a4*a1);
  a3=(a3*a4);
  a5=(a5+a3);
  if (res[0]!=0) res[0][8]=a5;
  a5=arg[0] ? arg[0][9] : 0;
  a3=cos(a5);
  a4=casadi_sq(a3);
  a1=cos(a4);
  a1=(a0*a1);
  a2=sin(a5);
  a3=(a3+a3);
  a4=sin(a4);
  a0=(a0*a5);
  a4=(a4*a0);
  a3=(a3*a4);
  a2=(a2*a3);
  a1=(a1+a2);
  if (res[0]!=0) res[0][9]=a1;
  return 0;
}

CASADI_SYMBOL_EXPORT int grad_phi(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, void* mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT void grad_phi_incref(void) {
}

CASADI_SYMBOL_EXPORT void grad_phi_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int grad_phi_n_in(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_int grad_phi_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT const char* grad_phi_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* grad_phi_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* grad_phi_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* grad_phi_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int grad_phi_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 1;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
