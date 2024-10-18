/**
 * @file frontend.h
 * @author admiralm
 */

#ifndef FRONTEND_H
#define FRONTEND_H

#include <ncurses.h>

#include "backend.h"

#define BOARD_BORDER_BEGIN_Y 0
#define BOARD_BORDER_BEGIN_X 0
#define BOARD_BORDER_END_Y 26
#define BOARD_BORDER_END_X 50

#define GAME_FIELD_BORDER_BEGIN_Y 1
#define GAME_FIELD_BORDER_BEGIN_X 1
#define GAME_FIELD_BORDER_END_Y \
  (GAME_FIELD_BORDER_BEGIN_Y + GAME_FIELD_HEIGHT + 1)
#define GAME_FIELD_BORDER_END_X \
  (GAME_FIELD_BORDER_BEGIN_X + GAME_FIELD_WIDTH * 2 + 1)

/**
 * @brief
 * Включает ncurses-режим.
 */
void ncursesTurnOn();

/**
 * @brief
 * Очищает Экран
 *
 */
void clearBoard();
void borderPrint(int begin_y, int begin_x, int end_y, int end_x);
void infoPrint(GameInfo_t *game_info);
void fieldPrint(GameInfo_t *game_info);
void nextFigurePrint(int **next);
void statusWindowPrint(int status);

void boardDisplay(GameInfo_t *game_info);

#endif