#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int return_value = ERROR_INCORRECT_MATRIX;

  if (A && result && A->matrix) {
    if (A->rows == A->columns) {
      if (A->rows == 1) {
        *result = **A->matrix;
      } else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else {
        *result = 0;
        matrix_t minor;

        //По первой строке
        for (int i = 0; i < A->columns; i++) {
          double det = 0;
          getMinor(A, 0, i, &minor);
          if (s21_determinant(&minor, &det) == OK) {
            *result += A->matrix[0][i] * pow(-1, i) * det;
          }
          s21_remove_matrix(&minor);
        }
      }
      return_value = OK;
    } else {
      return_value = CALCULATION_ERROR;
    }
  }

  return return_value;
}