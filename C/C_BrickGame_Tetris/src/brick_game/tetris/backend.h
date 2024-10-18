/**
 * @file backend.h
 * @author admiralm
 */

#ifndef BACKEND_H
#define BACKEND_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "figure.h"

#define GAME_FIELD_WIDTH 10
#define GAME_FIELD_HEIGHT 20
#define START_POSITION_Y 0
#define START_POSITION_X 3
#define SPEED 1000

typedef enum {
  START,
  BEGIN_POSITION,
  MOVEMENT,
  PAUSE,
  END_POSITION,
  GAME_OVER,
  EXIT
} Status_t;

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

void userInput(UserAction_t action, bool hold);
GameInfo_t updateCurrentState();

//===================== Дополнительные Функции
//=====================================

void initGame();
void startStatus();
void generateFigure();
void beginPositionStatus();
void eraseFigureFromField();
void moveFigureRight();
void moveFigureLeft();
void moveFigureDown();
void rotationFigure();
void insertFigureIntoField();
void movementStatus();
void endPositionStatus();
void calculateScore(int number_erased_lines);
int **newMatrix(int rows, int columns);
void zeroMatrix(int rows, int columns, int **matrix);
void deleteMatrix(int rows, int **matrix);
void deleteGameInfo(GameInfo_t *g_info);

int getHighScore();
void setHighScore();

bool checkErrorFlag();
void gameLog(char *str);

//====================== Functions for Testing Program =============
Figure_t funcForTestFigureNow();
Figure_t funcForTestFigureNext();

#endif