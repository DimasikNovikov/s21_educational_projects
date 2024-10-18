#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = FAILURE;

  if (A && B && A->matrix && B->matrix) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1.0e-7) {
            return return_value;
          }
        }
      }
      return_value = SUCCESS;
    }
  }

  return return_value;
}