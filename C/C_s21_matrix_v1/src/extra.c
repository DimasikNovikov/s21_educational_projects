#include "s21_matrix.h"

/* void displayMatrix(const matrix_t *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      printf("%.7lf", m->matrix[i][j]);
      if (j < m->columns) {
        putchar(' ');
      }
    }
    putchar('\n');
  }
  putchar('\n');
} */

matrix_t matrixDoesNotExist() {
  matrix_t M;
  M.matrix = NULL;
  M.rows = 0;
  M.columns = 0;

  return M;
}

void getMinor(matrix_t *A, int row, int column, matrix_t *minor) {
  s21_create_matrix(A->rows - 1, A->columns - 1, minor);

  for (int i = 0, i_minor = 0; i < A->rows; i++) {
    for (int j = 0, j_minor = 0; j < A->columns && i != row; j++) {
      if (j != column) {
        minor->matrix[i_minor][j_minor] = A->matrix[i][j];
        j_minor++;
      }
    }
    if (i != row) {
      i_minor++;
    }
  }
}