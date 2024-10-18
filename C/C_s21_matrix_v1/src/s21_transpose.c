#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_value = ERROR_INCORRECT_MATRIX;

  if (A && result && A->matrix) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
    return_value = OK;
  }

  return return_value;
}