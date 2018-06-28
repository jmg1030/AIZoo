/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CortexNet_types.h
 *
 * Code generation for function 'CortexNet'
 *
 */

#ifndef CORTEXNET_TYPES_H
#define CORTEXNET_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

typedef struct {
  double time;
  double dt;
} struct0_T;

typedef struct {
  double Ipop;
  double Epop;
  double A;
  double I[1000100];
  double W[10000];
  double tau[100];
  double syn[100];
} struct1_T;

typedef struct {
  emxArray_real_T *t;
  emxArray_real_T *x;
  emxArray_real_T *s;
  emxArray_real_T *f;
} struct2_T;

#endif

/* End of code generation (CortexNet_types.h) */
