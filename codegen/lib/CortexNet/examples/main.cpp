/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.cpp
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "rt_nonfinite.h"
#include "CortexNet.h"
#include "main.h"
#include "CortexNet_terminate.h"
#include "CortexNet_emxAPI.h"
#include "CortexNet_initialize.h"

/* Function Declarations */
static void argInit_100x10001_real_T(double result[1000100]);
static void argInit_100x100_real_T(double result[10000]);
static void argInit_100x1_real_T(double result[100]);
static double argInit_real_T();
static struct0_T argInit_struct0_T();
static void argInit_struct1_T(struct1_T *result);
static void main_CortexNet();

/* Function Definitions */
static void argInit_100x10001_real_T(double result[1000100])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 100; idx0++) {
    for (idx1 = 0; idx1 < 10001; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 100 * idx1] = argInit_real_T();
    }
  }
}

static void argInit_100x100_real_T(double result[10000])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 100; idx0++) {
    for (idx1 = 0; idx1 < 100; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 100 * idx1] = argInit_real_T();
    }
  }
}

static void argInit_100x1_real_T(double result[100])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 100; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static double argInit_real_T()
{
  return 0.0;
}

static struct0_T argInit_struct0_T()
{
  struct0_T result;

  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result.time = argInit_real_T();
  result.dt = argInit_real_T();
  return result;
}

static void argInit_struct1_T(struct1_T *result)
{
  /* Set the value of each structure field.
     Change this value to the value that the application requires. */
  result->Ipop = argInit_real_T();
  result->Epop = argInit_real_T();
  result->A = argInit_real_T();
  argInit_100x10001_real_T(result->I);
  argInit_100x100_real_T(result->W);
  argInit_100x1_real_T(result->tau);
  argInit_100x1_real_T(result->syn);
}

static void main_CortexNet()
{
  struct2_T Values;
  static struct1_T r1;
  struct0_T r2;
  emxInit_struct2_T(&Values);

  /* Initialize function 'CortexNet' input arguments. */
  /* Initialize function input argument 'TimeParams'. */
  /* Initialize function input argument 'Neurons'. */
  /* Call the entry-point 'CortexNet'. */
  argInit_struct1_T(&r1);
  r2 = argInit_struct0_T();
  CortexNet(&r2, &r1, &Values);
  emxDestroy_struct2_T(Values);
}

int main(int, const char * const [])
{
  /* Initialize the application.
     You do not need to do this more than one time. */
  CortexNet_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_CortexNet();

  /* Terminate the application.
     You do not need to do this more than one time. */
  CortexNet_terminate();
  return 0;
}

/* End of code generation (main.cpp) */
