//
// Copyright (C) 2011--2014 Karl Wette
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with with program; see the file COPYING. If not, write to the
// Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
// MA  02111-1307  USA
//

// Code for SWIG tests of the LAL bindings.
// Author: Karl Wette

#include "swiglal_config.h"
#include <lal/SWIGLALTest.h>
#include <lal/XLALError.h>
#include <lal/Date.h>

#ifdef __GNUC__
#define UNUSED __attribute__ ((unused))
#else
#define UNUSED
#endif

// Test various combinations of 1D and 2D fixed arrays
// with structs, struct/enum type, and global variables.
UNUSED const swig_lal_test_struct swig_lal_test_struct_const = {
  2, 3, 5.7, "abcde", {1,2,3}, {{4,5,6},{7,8,9}},
  {swig_lal_test_enum_a,swig_lal_test_enum_b,swig_lal_test_enum_c}
};
UNUSED swig_lal_test_struct swig_lal_test_struct_vector[3];
UNUSED swig_lal_test_struct swig_lal_test_struct_matrix[2][3];
UNUSED swig_lal_test_enum swig_lal_test_enum_vector[3];
UNUSED swig_lal_test_enum swig_lal_test_enum_matrix[2][3];
UNUSED INT4 swig_lal_test_empty_INT4_vector[0];
UNUSED INT4 swig_lal_test_INT4_vector[3];
UNUSED INT4 swig_lal_test_INT4_matrix[2][3];
UNUSED const INT4 swig_lal_test_INT4_const_vector[3] = {1, 2, 4};
UNUSED const INT4 swig_lal_test_INT4_const_matrix[2][3] = {{1, 2, 4}, {2, 4, 8}};
UNUSED REAL8 swig_lal_test_REAL8_vector[3];
UNUSED REAL8 swig_lal_test_REAL8_matrix[2][3];
UNUSED COMPLEX8 swig_lal_test_COMPLEX8_vector[3];
UNUSED COMPLEX8 swig_lal_test_COMPLEX8_matrix[2][3];

// Test fixed and dynamic arrays typemaps.
void swig_lal_test_copyin_array1(REAL8 INPUT[3], REAL8 scale, REAL8 OUTPUT[3]) {
  for (int i = 0; i < 3; ++i) {
    OUTPUT[i] = scale * INPUT[i];
  }
}
void swig_lal_test_copyin_array2(INT4 INPUT[3][2], INT4 scale, INT4 OUTPUT[3][2]) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      OUTPUT[i][j] = scale * INPUT[i][j];
    }
  }
}

// Test input views of array structs.
BOOLEAN swig_lal_test_viewin_REAL4Vector(REAL4Vector* copyout, const REAL4Vector* viewin) {
  if (!copyout || !copyout->data || !viewin || !viewin->data || copyout->length != viewin->length) {
    return 0;
  }
  for (size_t i = 0; i < viewin->length; ++i) {
    copyout->data[i] = viewin->data[i];
  }
  return 1;
}
BOOLEAN swig_lal_test_viewinout_REAL4Vector(REAL4Vector* viewout, REAL4Vector* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->length != viewin->length) {
    return 0;
  }
  for (size_t i = 0; i < viewin->length; ++i) {
    viewout->data[i] = viewin->data[i];
    viewin->data[i] = viewin->data[i] * 2.0;
  }
  return 1;
}
BOOLEAN swig_lal_test_copyinout_REAL4Vector(REAL4Vector* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  for (size_t i = 0; i < copyinout->length; ++i) {
    copyinout->data[i] = copyinout->data[i] * 3.0;
  }
  return 1;
}
BOOLEAN swig_lal_test_viewin_REAL8Vector(REAL8Vector* copyout, const REAL8Vector* viewin) {
  if (!copyout || !copyout->data || !viewin || !viewin->data || copyout->length != viewin->length) {
    return 0;
  }
  for (size_t i = 0; i < viewin->length; ++i) {
    copyout->data[i] = viewin->data[i];
  }
  return 1;
}
BOOLEAN swig_lal_test_viewinout_REAL8Vector(REAL8Vector* viewout, REAL8Vector* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->length != viewin->length) {
    return 0;
  }
  for (size_t i = 0; i < viewin->length; ++i) {
    viewout->data[i] = viewin->data[i];
    viewin->data[i] = viewin->data[i] * 2.0;
  }
  return 1;
}
BOOLEAN swig_lal_test_copyinout_REAL8Vector(REAL8Vector* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  for (size_t i = 0; i < copyinout->length; ++i) {
    copyinout->data[i] = copyinout->data[i] * 3.0;
  }
  return 1;
}
BOOLEAN swig_lal_test_viewin_COMPLEX8Vector(COMPLEX8Vector* copyout, const COMPLEX8Vector* viewin) {
  if (!copyout || !copyout->data || !viewin || !viewin->data || copyout->length != viewin->length) {
    return 0;
  }
  for (size_t i = 0; i < viewin->length; ++i) {
    copyout->data[i] = viewin->data[i];
  }
  return 1;
}
BOOLEAN swig_lal_test_viewinout_COMPLEX8Vector(COMPLEX8Vector* viewout, COMPLEX8Vector* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->length != viewin->length) {
    return 0;
  }
  for (size_t i = 0; i < viewin->length; ++i) {
    viewout->data[i] = viewin->data[i];
    viewin->data[i] = crectf(crealf(viewin->data[i]) * 2.0, cimagf(viewin->data[i]) * 2.0);
  }
  return 1;
}
BOOLEAN swig_lal_test_copyinout_COMPLEX8Vector(COMPLEX8Vector* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  for (size_t i = 0; i < copyinout->length; ++i) {
    copyinout->data[i] = copyinout->data[i] * 3.0;
  }
  return 1;
}
BOOLEAN swig_lal_test_viewin_COMPLEX16Vector(COMPLEX16Vector* copyout, const COMPLEX16Vector* viewin) {
  if (!copyout || !copyout->data || !viewin || !viewin->data || copyout->length != viewin->length) {
    return 0;
  }
  for (size_t i = 0; i < viewin->length; ++i) {
    copyout->data[i] = viewin->data[i];
  }
  return 1;
}
BOOLEAN swig_lal_test_viewinout_COMPLEX16Vector(COMPLEX16Vector* viewout, COMPLEX16Vector* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->length != viewin->length) {
    return 0;
  }
  for (size_t i = 0; i < viewin->length; ++i) {
    viewout->data[i] = viewin->data[i];
    viewin->data[i] = crect(creal(viewin->data[i]) * 2.0, cimag(viewin->data[i]) * 2.0);
  }
  return 1;
}
BOOLEAN swig_lal_test_copyinout_COMPLEX16Vector(COMPLEX16Vector* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  for (size_t i = 0; i < copyinout->length; ++i) {
    copyinout->data[i] = copyinout->data[i] * 3.0;
  }
  return 1;
}
BOOLEAN swig_lal_test_viewin_REAL4VectorSequence(REAL4VectorSequence* copyout, const REAL4VectorSequence* viewin) {
  if (!copyout || !copyout->data || !viewin || !viewin->data || copyout->length != viewin->length || copyout->vectorLength != viewin->vectorLength) {
    return 0;
  }
  const size_t n = viewin->vectorLength;
  for (size_t i = 0; i < viewin->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      copyout->data[i*n + j] = viewin->data[i*n + j];
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_viewinout_REAL4VectorSequence(REAL4VectorSequence* viewout, REAL4VectorSequence* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->length != viewin->length || viewout->vectorLength != viewin->vectorLength) {
    return 0;
  }
  const size_t n = viewin->vectorLength;
  for (size_t i = 0; i < viewin->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      viewout->data[i*n + j] = viewin->data[i*n + j];
      viewin->data[i*n + j] = viewin->data[i*n + j] * 2.0;
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_copyinout_REAL4VectorSequence(REAL4VectorSequence* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  const size_t n = copyinout->vectorLength;
  for (size_t i = 0; i < copyinout->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      copyinout->data[i*n + j] = copyinout->data[i*n + j] * 3.0;
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_viewin_REAL8VectorSequence(REAL8VectorSequence* copyout, const REAL8VectorSequence* viewin) {
  if (!copyout || !copyout->data || !viewin || !viewin->data || copyout->length != viewin->length || copyout->vectorLength != viewin->vectorLength) {
    return 0;
  }
  const size_t n = viewin->vectorLength;
  for (size_t i = 0; i < viewin->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      copyout->data[i*n + j] = viewin->data[i*n + j];
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_viewinout_REAL8VectorSequence(REAL8VectorSequence* viewout, REAL8VectorSequence* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->length != viewin->length || viewout->vectorLength != viewin->vectorLength) {
    return 0;
  }
  const size_t n = viewin->vectorLength;
  for (size_t i = 0; i < viewin->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      viewout->data[i*n + j] = viewin->data[i*n + j];
      viewin->data[i*n + j] = viewin->data[i*n + j] * 2.0;
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_copyinout_REAL8VectorSequence(REAL8VectorSequence* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  const size_t n = copyinout->vectorLength;
  for (size_t i = 0; i < copyinout->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      copyinout->data[i*n + j] = copyinout->data[i*n + j] * 3.0;
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_viewin_COMPLEX8VectorSequence(COMPLEX8VectorSequence* copyout, const COMPLEX8VectorSequence* viewin) {
  if (!copyout || !copyout->data || !viewin || !viewin->data || copyout->length != viewin->length || copyout->vectorLength != viewin->vectorLength) {
    return 0;
  }
  const size_t n = viewin->vectorLength;
  for (size_t i = 0; i < viewin->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      copyout->data[i*n + j] = viewin->data[i*n + j];
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_viewinout_COMPLEX8VectorSequence(COMPLEX8VectorSequence* viewout, COMPLEX8VectorSequence* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->length != viewin->length || viewout->vectorLength != viewin->vectorLength) {
    return 0;
  }
  const size_t n = viewin->vectorLength;
  for (size_t i = 0; i < viewin->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      viewout->data[i*n + j] = viewin->data[i*n + j];
      viewin->data[i*n + j] = crectf(crealf(viewin->data[i*n + j]) * 2.0, cimagf(viewin->data[i*n + j]) * 2.0);
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_copyinout_COMPLEX8VectorSequence(COMPLEX8VectorSequence* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  const size_t n = copyinout->vectorLength;
  for (size_t i = 0; i < copyinout->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      copyinout->data[i*n + j] = copyinout->data[i*n + j] * 3.0;
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_viewin_COMPLEX16VectorSequence(COMPLEX16VectorSequence* copyout, const COMPLEX16VectorSequence* viewin) {
  if (!copyout || !copyout->data || !viewin || !viewin->data || copyout->length != viewin->length || copyout->vectorLength != viewin->vectorLength) {
    return 0;
  }
  const size_t n = viewin->vectorLength;
  for (size_t i = 0; i < viewin->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      copyout->data[i*n + j] = viewin->data[i*n + j];
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_viewinout_COMPLEX16VectorSequence(COMPLEX16VectorSequence* viewout, COMPLEX16VectorSequence* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->length != viewin->length || viewout->vectorLength != viewin->vectorLength) {
    return 0;
  }
  const size_t n = viewin->vectorLength;
  for (size_t i = 0; i < viewin->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      viewout->data[i*n + j] = viewin->data[i*n + j];
      viewin->data[i*n + j] = crect(creal(viewin->data[i*n + j]) * 2.0, cimag(viewin->data[i*n + j]) * 2.0);
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_copyinout_COMPLEX16VectorSequence(COMPLEX16VectorSequence* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  const size_t n = copyinout->vectorLength;
  for (size_t i = 0; i < copyinout->length; ++i) {
    for (size_t j = 0; j < n; ++j) {
      copyinout->data[i*n + j] = copyinout->data[i*n + j] * 3.0;
    }
  }
  return 1;
}
BOOLEAN swig_lal_test_viewin_gsl_vector_float(gsl_vector_float* copyout, const gsl_vector_float* viewin) {
  if (!copyout || !viewin || copyout->size != viewin->size) {
    return 0;
  }
  gsl_vector_float_memcpy(copyout, viewin);
  return 1;
}
BOOLEAN swig_lal_test_viewinout_gsl_vector_float(gsl_vector_float* viewout, gsl_vector_float* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->size != viewin->size) {
    return 0;
  }
  gsl_vector_float_memcpy(viewout, viewin);
  gsl_vector_float_scale(viewin, 2.0);
  return 1;
}
BOOLEAN swig_lal_test_copyinout_gsl_vector_float(gsl_vector_float* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  gsl_vector_float_scale(copyinout, 3.0);
  return 1;
}
BOOLEAN swig_lal_test_viewin_gsl_vector(gsl_vector* copyout, const gsl_vector* viewin) {
  if (!copyout || !viewin || copyout->size != viewin->size) {
    return 0;
  }
  gsl_vector_memcpy(copyout, viewin);
  return 1;
}
BOOLEAN swig_lal_test_viewinout_gsl_vector(gsl_vector* viewout, gsl_vector* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->size != viewin->size) {
    return 0;
  }
  gsl_vector_memcpy(viewout, viewin);
  gsl_vector_scale(viewin, 2.0);
  return 1;
}
BOOLEAN swig_lal_test_copyinout_gsl_vector(gsl_vector* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  gsl_vector_scale(copyinout, 3.0);
  return 1;
}
BOOLEAN swig_lal_test_viewin_gsl_vector_complex_float(gsl_vector_complex_float* copyout, const gsl_vector_complex_float* viewin) {
  if (!copyout || !viewin || copyout->size != viewin->size) {
    return 0;
  }
  gsl_vector_complex_float_memcpy(copyout, viewin);
  return 1;
}
BOOLEAN swig_lal_test_viewinout_gsl_vector_complex_float(gsl_vector_complex_float* viewout, gsl_vector_complex_float* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->size != viewin->size) {
    return 0;
  }
  gsl_vector_complex_float_memcpy(viewout, viewin);
  gsl_complex_float z;
  GSL_SET_COMPLEX(&z, 2.0, 0.0);
  gsl_vector_complex_float_scale(viewin, z);
  return 1;
}
BOOLEAN swig_lal_test_copyinout_gsl_vector_complex_float(gsl_vector_complex_float* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  gsl_complex_float z;
  GSL_SET_COMPLEX(&z, 3.0, 0.0);
  gsl_vector_complex_float_scale(copyinout, z);
  return 1;
}
BOOLEAN swig_lal_test_viewin_gsl_vector_complex(gsl_vector_complex* copyout, const gsl_vector_complex* viewin) {
  if (!copyout || !viewin || copyout->size != viewin->size) {
    return 0;
  }
  gsl_vector_complex_memcpy(copyout, viewin);
  return 1;
}
BOOLEAN swig_lal_test_viewinout_gsl_vector_complex(gsl_vector_complex* viewout, gsl_vector_complex* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->size != viewin->size) {
    return 0;
  }
  gsl_vector_complex_memcpy(viewout, viewin);
  gsl_complex z;
  GSL_SET_COMPLEX(&z, 2.0, 0.0);
  gsl_vector_complex_scale(viewin, z);
  return 1;
}
BOOLEAN swig_lal_test_copyinout_gsl_vector_complex(gsl_vector_complex* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  gsl_complex z;
  GSL_SET_COMPLEX(&z, 3.0, 0.0);
  gsl_vector_complex_scale(copyinout, z);
  return 1;
}
BOOLEAN swig_lal_test_viewin_gsl_matrix_float(gsl_matrix_float* copyout, const gsl_matrix_float* viewin) {
  if (!copyout || !viewin || copyout->size1 != viewin->size1 || copyout->size2 != viewin->size2) {
    return 0;
  }
  gsl_matrix_float_memcpy(copyout, viewin);
  return 1;
}
BOOLEAN swig_lal_test_viewinout_gsl_matrix_float(gsl_matrix_float* viewout, gsl_matrix_float* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->size1 != viewin->size1 || viewout->size2 != viewin->size2) {
    return 0;
  }
  gsl_matrix_float_memcpy(viewout, viewin);
  gsl_matrix_float_scale(viewin, 2.0);
  return 1;
}
BOOLEAN swig_lal_test_copyinout_gsl_matrix_float(gsl_matrix_float* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  gsl_matrix_float_scale(copyinout, 3.0);
  return 1;
}
BOOLEAN swig_lal_test_viewin_gsl_matrix(gsl_matrix* copyout, const gsl_matrix* viewin) {
  if (!copyout || !viewin || copyout->size1 != viewin->size1 || copyout->size2 != viewin->size2) {
    return 0;
  }
  gsl_matrix_memcpy(copyout, viewin);
  return 1;
}
BOOLEAN swig_lal_test_viewinout_gsl_matrix(gsl_matrix* viewout, gsl_matrix* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->size1 != viewin->size1 || viewout->size2 != viewin->size2) {
    return 0;
  }
  gsl_matrix_memcpy(viewout, viewin);
  gsl_matrix_scale(viewin, 2.0);
  return 1;
}
BOOLEAN swig_lal_test_copyinout_gsl_matrix(gsl_matrix* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  gsl_matrix_scale(copyinout, 3.0);
  return 1;
}
BOOLEAN swig_lal_test_viewin_gsl_matrix_complex_float(gsl_matrix_complex_float* copyout, const gsl_matrix_complex_float* viewin) {
  if (!copyout || !viewin || copyout->size1 != viewin->size1 || copyout->size2 != viewin->size2) {
    return 0;
  }
  gsl_matrix_complex_float_memcpy(copyout, viewin);
  return 1;
}
BOOLEAN swig_lal_test_viewinout_gsl_matrix_complex_float(gsl_matrix_complex_float* viewout, gsl_matrix_complex_float* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->size1 != viewin->size1 || viewout->size2 != viewin->size2) {
    return 0;
  }
  gsl_matrix_complex_float_memcpy(viewout, viewin);
  gsl_complex_float z;
  GSL_SET_COMPLEX(&z, 2.0, 0.0);
  gsl_matrix_complex_float_scale(viewin, z);
  return 1;
}
BOOLEAN swig_lal_test_copyinout_gsl_matrix_complex_float(gsl_matrix_complex_float* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  gsl_complex_float z;
  GSL_SET_COMPLEX(&z, 3.0, 0.0);
  gsl_matrix_complex_float_scale(copyinout, z);
  return 1;
}
BOOLEAN swig_lal_test_viewin_gsl_matrix_complex(gsl_matrix_complex* copyout, const gsl_matrix_complex* viewin) {
  if (!copyout || !viewin || copyout->size1 != viewin->size1 || copyout->size2 != viewin->size2) {
    return 0;
  }
  gsl_matrix_complex_memcpy(copyout, viewin);
  return 1;
}
BOOLEAN swig_lal_test_viewinout_gsl_matrix_complex(gsl_matrix_complex* viewout, gsl_matrix_complex* viewin) {
  if (!viewout || !viewout->data || !viewin || !viewin->data || viewout->size1 != viewin->size1 || viewout->size2 != viewin->size2) {
    return 0;
  }
  gsl_matrix_complex_memcpy(viewout, viewin);
  gsl_complex z;
  GSL_SET_COMPLEX(&z, 2.0, 0.0);
  gsl_matrix_complex_scale(viewin, z);
  return 1;
}
BOOLEAN swig_lal_test_copyinout_gsl_matrix_complex(gsl_matrix_complex* copyinout) {
  if (!copyinout || !copyinout->data) {
    return 0;
  }
  gsl_complex z;
  GSL_SET_COMPLEX(&z, 3.0, 0.0);
  gsl_matrix_complex_scale(copyinout, z);
  return 1;
}

// Test dynamic array of pointer access.
swig_lal_test_arrayofptrs* swig_lal_test_Create_arrayofptrs(UINT4 length) {
  swig_lal_test_arrayofptrs* ap = (swig_lal_test_arrayofptrs*)XLALMalloc(sizeof(swig_lal_test_arrayofptrs));
  XLAL_CHECK_NULL(ap != NULL, XLAL_ENOMEM);
  ap->length = length;
  ap->data = (swig_lal_test_arrayofdata**)XLALCalloc(ap->length, sizeof(swig_lal_test_arrayofdata*));
  XLAL_CHECK_NULL(ap->data != NULL, XLAL_ENOMEM);
  for (UINT4 i = 0; i < ap->length; ++i) {
    ap->data[i] = (swig_lal_test_arrayofdata*)XLALMalloc(sizeof(swig_lal_test_arrayofdata));
    XLAL_CHECK_NULL(ap->data[i] != NULL, XLAL_ENOMEM);
    ap->data[i]->length = 2*length;
    ap->data[i]->data = (INT4*)XLALCalloc(ap->data[i]->length, sizeof(INT4));
    XLAL_CHECK_NULL(ap->data[i]->data != NULL, XLAL_ENOMEM);
    for (UINT4 j = 0; j < ap->data[i]->length; ++j) {
      ap->data[i]->data[j] = 42*length*i + j;
    }
  }
  return ap;
}
void swig_lal_test_Destroy_arrayofptrs(swig_lal_test_arrayofptrs* ap) {
  if (ap) {
    if (ap->data) {
      for (UINT4 i = 0; i < ap->length; ++i) {
        if (ap->data[i]) {
          if (ap->data[i]->data) {
            XLALFree(ap->data[i]->data);
          }
          XLALFree(ap->data[i]);
        }
      }
      XLALFree(ap->data);
    }
    XLALFree(ap);
  }
}

// Test LIGOTimeGPS operations.
REAL8 swig_lal_test_noptrgps(const LIGOTimeGPS gps) {
  return XLALGPSGetREAL8(&gps);
}
