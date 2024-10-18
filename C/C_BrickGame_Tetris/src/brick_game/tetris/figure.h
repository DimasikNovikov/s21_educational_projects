/**
 * @file figure.h
 * @author admiralm
 *
 */

#ifndef FIGURE_H
#define FIGURE_H

#define FIGURE_SIZE 4

typedef enum { O, I, S, Z, J, L, T } NameFigure_t;

typedef struct {
  int matrix[FIGURE_SIZE][FIGURE_SIZE];
  NameFigure_t name;
  int rotation;
  int x;
  int y;
} Figure_t;

void identifyFigure(Figure_t *figure);
void figureEmpty(int matrix[][FIGURE_SIZE]);
void figureO(int matrix[][FIGURE_SIZE]);
void figureI(int rotation, int matrix[][FIGURE_SIZE]);
void figureS(int rotation, int matrix[][FIGURE_SIZE]);
void figureZ(int rotation, int matrix[][FIGURE_SIZE]);
void figureL(int rotation, int matrix[][FIGURE_SIZE]);
void figureJ(int rotation, int matrix[][FIGURE_SIZE]);
void figureT(int rotation, int matrix[][FIGURE_SIZE]);

#endif