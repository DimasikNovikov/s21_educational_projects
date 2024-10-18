#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_value = ERROR_INCORRECT_MATRIX;

  if (result) {
    *result = matrixDoesNotExist();

    if (rows > 0 && columns > 0) {
      result->rows = rows;
      result->columns = columns;

      result->matrix = (double **)calloc(rows, sizeof(double *));
      if (result->matrix != NULL) {
        for (int i = 0; i < rows; i++) {
          result->matrix[i] = (double *)calloc(columns, sizeof(double));
          if (result->matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
              free(result->matrix[j]);
              result->matrix[j] = NULL;
            }
            free(result->matrix);
            result->matrix = NULL;
            return_value = ERROR_INCORRECT_MATRIX;
            break;
          } else {
            return_value = OK;
          }
        }
      }
    }
  }

  return return_value;
}
