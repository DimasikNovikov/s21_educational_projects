#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_value = ERROR_INCORRECT_MATRIX;

  if (A && result && A->matrix) {
    *result = matrixDoesNotExist();
    if (A->rows == A->columns) {
      if (A->rows == 1) {
        s21_create_matrix(1, 1, result);
        **result->matrix = 1;
      } else {
        s21_create_matrix(A->rows, A->columns, result);
        matrix_t minor;

        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            getMinor(A, i, j, &minor);
            double det = 0;
            if (s21_determinant(&minor, &det) == OK) {
              result->matrix[i][j] = pow(-1, i + j) * det;
            }
            s21_remove_matrix(&minor);
          }
        }
      }
      return_value = OK;

    } else {
      return_value = CALCULATION_ERROR;
    }
  }

  return return_value;
}