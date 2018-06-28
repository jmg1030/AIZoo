/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CortexNet.cpp
 *
 * Code generation for function 'CortexNet'
 *
 */

/* Include files */
#include <cmath>
#include <string.h>
#include "rt_nonfinite.h"
#include "CortexNet.h"
#include "CortexNet_emxutil.h"

/* Function Definitions */
void CortexNet(const struct0_T *TimeParams, const struct1_T *Neurons, struct2_T *
               Values)
{
  double dt;
  emxArray_real_T *t;
  int i;
  double ndbl;
  double apnd;
  emxArray_real_T *x;
  double cdiff;
  int nm1d2;
  int n;
  emxArray_real_T *s;
  emxArray_real_T *f;
  int k;
  emxArray_int32_T *r0;
  emxArray_real_T *b_s;
  emxArray_real_T *b_x;
  double y[100];
  double c_x[100];
  dt = TimeParams->dt;
  emxInit_real_T(&t, 2);
  if (rtIsNaN(TimeParams->dt) || rtIsNaN(TimeParams->time)) {
    i = t->size[0] * t->size[1];
    t->size[0] = 1;
    t->size[1] = 1;
    emxEnsureCapacity_real_T(t, i);
    t->data[0] = rtNaN;
  } else if ((TimeParams->dt == 0.0) || ((0.0 < TimeParams->time) &&
              (TimeParams->dt < 0.0)) || ((TimeParams->time < 0.0) &&
              (TimeParams->dt > 0.0))) {
    i = t->size[0] * t->size[1];
    t->size[0] = 1;
    t->size[1] = 0;
    emxEnsureCapacity_real_T(t, i);
  } else if (rtIsInf(TimeParams->time) && (rtIsInf(TimeParams->dt) || (0.0 ==
               TimeParams->time))) {
    i = t->size[0] * t->size[1];
    t->size[0] = 1;
    t->size[1] = 1;
    emxEnsureCapacity_real_T(t, i);
    t->data[0] = rtNaN;
  } else if (rtIsInf(TimeParams->dt)) {
    i = t->size[0] * t->size[1];
    t->size[0] = 1;
    t->size[1] = 1;
    emxEnsureCapacity_real_T(t, i);
    t->data[0] = 0.0;
  } else if (std::floor(TimeParams->dt) == TimeParams->dt) {
    i = t->size[0] * t->size[1];
    t->size[0] = 1;
    t->size[1] = (int)std::floor(TimeParams->time / TimeParams->dt) + 1;
    emxEnsureCapacity_real_T(t, i);
    nm1d2 = (int)std::floor(TimeParams->time / TimeParams->dt);
    for (i = 0; i <= nm1d2; i++) {
      t->data[t->size[0] * i] = TimeParams->dt * (double)i;
    }
  } else {
    ndbl = std::floor(TimeParams->time / TimeParams->dt + 0.5);
    apnd = ndbl * TimeParams->dt;
    if (TimeParams->dt > 0.0) {
      cdiff = apnd - TimeParams->time;
    } else {
      cdiff = TimeParams->time - apnd;
    }

    if (std::abs(cdiff) < 4.4408920985006262E-16 * std::abs(TimeParams->time)) {
      ndbl++;
      apnd = TimeParams->time;
    } else if (cdiff > 0.0) {
      apnd = (ndbl - 1.0) * TimeParams->dt;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    i = t->size[0] * t->size[1];
    t->size[0] = 1;
    t->size[1] = n;
    emxEnsureCapacity_real_T(t, i);
    if (n > 0) {
      t->data[0] = 0.0;
      if (n > 1) {
        t->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 1; k < nm1d2; k++) {
          ndbl = (double)k * dt;
          t->data[k] = ndbl;
          t->data[(n - k) - 1] = apnd - ndbl;
        }

        if (nm1d2 << 1 == n - 1) {
          t->data[nm1d2] = apnd / 2.0;
        } else {
          ndbl = (double)nm1d2 * TimeParams->dt;
          t->data[nm1d2] = ndbl;
          t->data[nm1d2 + 1] = apnd - ndbl;
        }
      }
    }
  }

  emxInit_real_T(&x, 2);
  cdiff = Neurons->Epop + Neurons->Ipop;
  i = x->size[0] * x->size[1];
  x->size[0] = (int)cdiff;
  x->size[1] = t->size[1];
  emxEnsureCapacity_real_T(x, i);
  nm1d2 = (int)cdiff * t->size[1];
  for (i = 0; i < nm1d2; i++) {
    x->data[i] = 0.0;
  }

  emxInit_real_T(&s, 2);
  i = s->size[0] * s->size[1];
  s->size[0] = (int)cdiff;
  s->size[1] = t->size[1];
  emxEnsureCapacity_real_T(s, i);
  nm1d2 = (int)cdiff * t->size[1];
  for (i = 0; i < nm1d2; i++) {
    s->data[i] = 0.0;
  }

  emxInit_real_T(&f, 2);
  i = f->size[0] * f->size[1];
  f->size[0] = (int)cdiff;
  f->size[1] = t->size[1];
  emxEnsureCapacity_real_T(f, i);
  nm1d2 = (int)cdiff * t->size[1];
  for (i = 0; i < nm1d2; i++) {
    f->data[i] = 0.0;
  }

  /*  */
  n = 0;
  emxInit_int32_T(&r0, 1);
  emxInit_real_T1(&b_s, 1);
  emxInit_real_T1(&b_x, 1);
  while (n <= t->size[1] - 2) {
    i = s->size[0];
    if (i == 1) {
      nm1d2 = s->size[0];
      i = b_s->size[0];
      b_s->size[0] = nm1d2;
      emxEnsureCapacity_real_T1(b_s, i);
      for (i = 0; i < nm1d2; i++) {
        b_s->data[i] = s->data[i + s->size[0] * n];
      }

      for (i = 0; i < 100; i++) {
        y[i] = 0.0;
        for (nm1d2 = 0; nm1d2 < 100; nm1d2++) {
          ndbl = y[i] + Neurons->W[i + 100 * nm1d2] * b_s->data[nm1d2];
          y[i] = ndbl;
        }
      }
    } else {
      memset(&y[0], 0, 100U * sizeof(double));
      for (k = 0; k < 100; k++) {
        if (s->data[k + s->size[0] * n] != 0.0) {
          nm1d2 = k * 100;
          for (i = 0; i < 100; i++) {
            ndbl = y[i] + s->data[k + s->size[0] * n] * Neurons->W[nm1d2 + i];
            y[i] = ndbl;
          }
        }
      }
    }

    nm1d2 = x->size[0];
    i = r0->size[0];
    r0->size[0] = nm1d2;
    emxEnsureCapacity_int32_T(r0, i);
    for (i = 0; i < nm1d2; i++) {
      r0->data[i] = i;
    }

    nm1d2 = x->size[0];
    i = b_s->size[0];
    b_s->size[0] = nm1d2;
    emxEnsureCapacity_real_T1(b_s, i);
    for (i = 0; i < nm1d2; i++) {
      b_s->data[i] = x->data[i + x->size[0] * n];
    }

    nm1d2 = x->size[0];
    i = b_x->size[0];
    b_x->size[0] = nm1d2;
    emxEnsureCapacity_real_T1(b_x, i);
    for (i = 0; i < nm1d2; i++) {
      b_x->data[i] = -x->data[i + x->size[0] * n];
    }

    for (i = 0; i < 100; i++) {
      c_x[i] = b_s->data[i] + ((b_x->data[i] + y[i]) + Neurons->I[i + 100 * n]) *
        dt / Neurons->tau[i];
    }

    nm1d2 = r0->size[0];
    for (i = 0; i < nm1d2; i++) {
      x->data[r0->data[i] + x->size[0] * (n + 1)] = c_x[i];
    }

    nm1d2 = s->size[0];
    i = r0->size[0];
    r0->size[0] = nm1d2;
    emxEnsureCapacity_int32_T(r0, i);
    for (i = 0; i < nm1d2; i++) {
      r0->data[i] = i;
    }

    nm1d2 = x->size[0];
    i = b_s->size[0];
    b_s->size[0] = nm1d2;
    emxEnsureCapacity_real_T1(b_s, i);
    for (i = 0; i < nm1d2; i++) {
      b_s->data[i] = x->data[i + x->size[0] * (n + 1)];
    }

    for (k = 0; k < 100; k++) {
      ndbl = b_s->data[k] * Neurons->syn[k];
      ndbl = std::atan(ndbl);
      y[k] = ndbl;
    }

    nm1d2 = r0->size[0];
    for (i = 0; i < nm1d2; i++) {
      s->data[r0->data[i] + s->size[0] * (n + 1)] = y[i];
    }

    /* 1./(1 + exp(-x(:,n+1).*syn)); */
    i = x->size[0];
    nm1d2 = x->size[0];
    if (nm1d2 == 0) {
      ndbl = 0.0;
    } else {
      nm1d2 = x->size[0];
      if (nm1d2 == 0) {
        ndbl = 0.0;
      } else {
        ndbl = x->data[x->size[0] * (n + 1)];
        for (k = 2; k <= i; k++) {
          ndbl += x->data[(k + x->size[0] * (n + 1)) - 1];
        }
      }
    }

    ndbl /= cdiff;
    nm1d2 = f->size[0];
    for (i = 0; i < nm1d2; i++) {
      f->data[i + f->size[0] * (n + 1)] = ndbl;
    }

    n++;
  }

  emxFree_real_T(&b_x);
  emxFree_real_T(&b_s);
  emxFree_int32_T(&r0);
  i = Values->t->size[0] * Values->t->size[1];
  Values->t->size[0] = 1;
  Values->t->size[1] = t->size[1];
  emxEnsureCapacity_real_T(Values->t, i);
  nm1d2 = t->size[0] * t->size[1];
  for (i = 0; i < nm1d2; i++) {
    Values->t->data[i] = t->data[i];
  }

  emxFree_real_T(&t);
  i = Values->x->size[0] * Values->x->size[1];
  Values->x->size[0] = x->size[0];
  Values->x->size[1] = x->size[1];
  emxEnsureCapacity_real_T(Values->x, i);
  nm1d2 = x->size[0] * x->size[1];
  for (i = 0; i < nm1d2; i++) {
    Values->x->data[i] = x->data[i];
  }

  emxFree_real_T(&x);
  i = Values->s->size[0] * Values->s->size[1];
  Values->s->size[0] = s->size[0];
  Values->s->size[1] = s->size[1];
  emxEnsureCapacity_real_T(Values->s, i);
  nm1d2 = s->size[0] * s->size[1];
  for (i = 0; i < nm1d2; i++) {
    Values->s->data[i] = s->data[i];
  }

  emxFree_real_T(&s);
  i = Values->f->size[0] * Values->f->size[1];
  Values->f->size[0] = f->size[0];
  Values->f->size[1] = f->size[1];
  emxEnsureCapacity_real_T(Values->f, i);
  nm1d2 = f->size[0] * f->size[1];
  for (i = 0; i < nm1d2; i++) {
    Values->f->data[i] = f->data[i];
  }

  emxFree_real_T(&f);
}

/* End of code generation (CortexNet.cpp) */
