/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CortexNet_emxAPI.h
 *
 * Code generation for function 'CortexNet_emxAPI'
 *
 */

#ifndef CORTEXNET_EMXAPI_H
#define CORTEXNET_EMXAPI_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "CortexNet_types.h"

/* Function Declarations */
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroy_struct2_T(struct2_T emxArray);
extern void emxInit_struct2_T(struct2_T *pStruct);

#endif

/* End of code generation (CortexNet_emxAPI.h) */
