#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_value = ERROR_INCORRECT_MATRIX;

  if (A && result && A->matrix) {
    *result = matrixDoesNotExist();
    if (A->rows == A->columns) {
      double det = 0;
      s21_determinant(A, &det);

      if (fabs(det) >= 1e-6) {
        matrix_t A_alg;
        matrix_t A_alg_T;
        s21_calc_complements(A, &A_alg);
        s21_transpose(&A_alg, &A_alg_T);

        s21_mult_number(&A_alg_T, 1.0 / det, result);

        s21_remove_matrix(&A_alg_T);
        s21_remove_matrix(&A_alg);

        return_value = OK;
      } else {
        return_value = CALCULATION_ERROR;
      }

    } else {
      return_value = CALCULATION_ERROR;
    }
  }

  return return_value;
}