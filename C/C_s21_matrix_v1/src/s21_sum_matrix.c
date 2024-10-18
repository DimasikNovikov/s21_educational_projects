#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = ERROR_INCORRECT_MATRIX;

  if (A && B && result && A->matrix && B->matrix) {
    *result = matrixDoesNotExist();
    if (A->rows == B->rows && A->columns == B->columns) {
      s21_create_matrix(A->rows, A->columns, result);

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }

      return_value = OK;
    } else {
      return_value = CALCULATION_ERROR;
    }
  }

  return return_value;
}