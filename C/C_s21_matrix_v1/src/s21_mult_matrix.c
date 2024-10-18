#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = ERROR_INCORRECT_MATRIX;

  if (A && B && result && A->matrix && B->matrix) {
    *result = matrixDoesNotExist();
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
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
