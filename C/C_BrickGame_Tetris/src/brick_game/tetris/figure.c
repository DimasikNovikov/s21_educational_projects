#include "figure.h"

void identifyFigure(Figure_t *figure) {
  switch (figure->name) {
    case O:
      figureO(figure->matrix);
      break;
    case I:
      figureI(figure->rotation, figure->matrix);
      break;
    case S:
      figureS(figure->rotation, figure->matrix);
      break;
    case Z:
      figureZ(figure->rotation, figure->matrix);
      break;
    case L:
      figureL(figure->rotation, figure->matrix);
      break;
    case J:
      figureJ(figure->rotation, figure->matrix);
      break;
    case T:
      figureT(figure->rotation, figure->matrix);
      break;
  }
}

void figureEmpty(int matrix[][FIGURE_SIZE]) {
  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      matrix[i][j] = 0;
    }
  }
}

void figureO(int matrix[][FIGURE_SIZE]) {
  figureEmpty(matrix);
  matrix[0][0] = matrix[0][1] = 1;
  matrix[1][0] = matrix[1][1] = 1;
}

void figureI(int rotation, int matrix[][FIGURE_SIZE]) {
  figureEmpty(matrix);

  rotation %= 2;
  switch (rotation) {
    case 0:
      matrix[0][0] = matrix[0][1] = 1;
      matrix[0][2] = matrix[0][3] = 1;
      break;
    case 1:
      matrix[0][0] = matrix[1][0] = 1;
      matrix[2][0] = matrix[3][0] = 1;
      break;
  }
}

void figureS(int rotation, int matrix[][FIGURE_SIZE]) {
  figureEmpty(matrix);

  rotation %= 2;
  switch (rotation) {
    case 0:
      matrix[0][1] = matrix[0][2] = 1;
      matrix[1][0] = matrix[1][1] = 1;
      break;
    case 1:
      matrix[0][0] = matrix[1][0] = 1;
      matrix[1][1] = matrix[2][1] = 1;
      break;
  }
}

void figureZ(int rotation, int matrix[][FIGURE_SIZE]) {
  figureEmpty(matrix);

  rotation %= 2;
  switch (rotation) {
    case 0:
      matrix[0][0] = matrix[0][1] = 1;
      matrix[1][1] = matrix[1][2] = 1;
      break;
    case 1:
      matrix[1][0] = matrix[2][0] = 1;
      matrix[0][1] = matrix[1][1] = 1;
      break;
  }
}

void figureL(int rotation, int matrix[][FIGURE_SIZE]) {
  figureEmpty(matrix);

  rotation %= 4;
  switch (rotation) {
    case 0:
      matrix[0][0] = matrix[0][1] = 1;
      matrix[0][2] = matrix[1][0] = 1;
      break;
    case 1:
      matrix[0][0] = matrix[1][0] = 1;
      matrix[2][0] = matrix[2][1] = 1;
      break;
    case 2:
      matrix[1][0] = matrix[1][1] = 1;
      matrix[1][2] = matrix[0][2] = 1;
      break;
    case 3:
      matrix[0][1] = matrix[1][1] = 1;
      matrix[2][1] = matrix[0][0] = 1;
      break;
  }
}

void figureJ(int rotation, int matrix[][FIGURE_SIZE]) {
  figureEmpty(matrix);

  rotation %= 4;
  switch (rotation) {
    case 0:
      matrix[0][0] = matrix[0][1] = 1;
      matrix[0][2] = matrix[1][2] = 1;
      break;
    case 1:
      matrix[0][0] = matrix[1][0] = 1;
      matrix[2][0] = matrix[0][1] = 1;
      break;
    case 2:
      matrix[1][0] = matrix[1][1] = 1;
      matrix[1][2] = matrix[0][0] = 1;
      break;
    case 3:
      matrix[0][1] = matrix[1][1] = 1;
      matrix[2][1] = matrix[2][0] = 1;
      break;
  }
}

void figureT(int rotation, int matrix[][FIGURE_SIZE]) {
  figureEmpty(matrix);

  rotation %= 4;
  switch (rotation) {
    case 0:
      matrix[0][0] = matrix[0][1] = 1;
      matrix[0][2] = matrix[1][1] = 1;
      break;
    case 1:
      matrix[0][0] = matrix[1][0] = 1;
      matrix[2][0] = matrix[1][1] = 1;
      break;
    case 2:
      matrix[1][0] = matrix[1][1] = 1;
      matrix[1][2] = matrix[0][1] = 1;
      break;
    case 3:
      matrix[0][1] = matrix[1][1] = 1;
      matrix[2][1] = matrix[1][0] = 1;
      break;
  }
}
