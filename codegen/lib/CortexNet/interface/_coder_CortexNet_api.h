/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_CortexNet_api.h
 *
 * Code generation for function '_coder_CortexNet_api'
 *
 */

#ifndef _CODER_CORTEXNET_API_H
#define _CODER_CORTEXNET_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_CortexNet_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T time;
  real_T dt;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T Ipop;
  real_T Epop;
  real_T A;
  real_T I[1000100];
  real_T W[10000];
  real_T tau[100];
  real_T syn[100];
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  emxArray_real_T *t;
  emxArray_real_T *x;
  emxArray_real_T *s;
  emxArray_real_T *f;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void CortexNet(struct0_T *TimeParams, struct1_T *Neurons, struct2_T
                      *Values);
extern void CortexNet_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1]);
extern void CortexNet_atexit(void);
extern void CortexNet_initialize(void);
extern void CortexNet_terminate(void);
extern void CortexNet_xil_terminate(void);

#endif

/* End of code generation (_coder_CortexNet_api.h) */
