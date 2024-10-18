#include "frontend.h"

void ncursesTurnOn() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, true);
  nodelay(stdscr, true);
}

void clearBoard() {
  for (int i = BOARD_BORDER_BEGIN_Y; i < BOARD_BORDER_END_Y; i++) {
    for (int j = BOARD_BORDER_BEGIN_X; j < BOARD_BORDER_END_X; j++) {
      mvaddch(i, j, ' ');
    }
  }
}

void boardDisplay(GameInfo_t *game_info) {
  clearBoard();
  borderPrint(BOARD_BORDER_BEGIN_Y, BOARD_BORDER_BEGIN_X, BOARD_BORDER_END_Y,
              BOARD_BORDER_END_X);
  borderPrint(GAME_FIELD_BORDER_BEGIN_Y, GAME_FIELD_BORDER_BEGIN_X,
              GAME_FIELD_BORDER_END_Y, GAME_FIELD_BORDER_END_X);
  infoPrint(game_info);

  if (game_info->pause == START) {
    statusWindowPrint(START);
  } else if (game_info->pause == PAUSE) {
    statusWindowPrint(PAUSE);
  } else if (game_info->pause == MOVEMENT) {
    fieldPrint(game_info);
  } else if (game_info->pause == GAME_OVER) {
    statusWindowPrint(GAME_OVER);
  }
}

void borderPrint(int begin_y, int begin_x, int end_y, int end_x) {
  mvaddch(begin_y, begin_x, ACS_ULCORNER);
  mvaddch(begin_y, end_x, ACS_URCORNER);
  mvaddch(end_y, begin_x, ACS_LLCORNER);
  mvaddch(end_y, end_x, ACS_LRCORNER);

  for (int i = begin_y + 1; i < end_y; i++) {
    mvaddch(i, begin_x, ACS_VLINE);
    mvaddch(i, end_x, ACS_VLINE);
  }

  for (int i = begin_x + 1; i < end_x; i++) {
    mvaddch(begin_y, i, ACS_HLINE);
    mvaddch(end_y, i, ACS_HLINE);
  }
}

void infoPrint(GameInfo_t *game_info) {
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 1, GAME_FIELD_BORDER_END_X + 3,
           "Score:");
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 2, GAME_FIELD_BORDER_END_X + 3, "%d",
           game_info->score);
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 4, GAME_FIELD_BORDER_END_X + 3,
           "High score:");
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 5, GAME_FIELD_BORDER_END_X + 3, "%d",
           game_info->high_score);

  char *str = "";
  if (game_info->level >= 10) {
    str = "(max level)";
  }

  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 7, GAME_FIELD_BORDER_END_X + 3,
           "Level:");
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 8, GAME_FIELD_BORDER_END_X + 3, "%d %s",
           game_info->level, str);
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 10, GAME_FIELD_BORDER_END_X + 3,
           "Speed:");
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 11, GAME_FIELD_BORDER_END_X + 3, "%d",
           game_info->speed);
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 13, GAME_FIELD_BORDER_END_X + 3,
           "Next:");
  nextFigurePrint(game_info->next);

  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 20, GAME_FIELD_BORDER_END_X + 2,
           "p - pause");
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 21, GAME_FIELD_BORDER_END_X + 2,
           "Space - rotation");
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 22, GAME_FIELD_BORDER_END_X + 2,
           "Left arrow - step left");
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 23, GAME_FIELD_BORDER_END_X + 2,
           "Right arrow - step right ");
  mvprintw(GAME_FIELD_BORDER_BEGIN_Y + 24, GAME_FIELD_BORDER_END_X + 2,
           "Down arrow - drop");
}

void nextFigurePrint(int **next) {
  int y = GAME_FIELD_BORDER_BEGIN_Y + 15;
  int x = GAME_FIELD_BORDER_END_X + 3;

  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      if (next[i][j] == 1) {
        mvaddch(y + i, x + (j * 2), '[');
        mvaddch(y + i, x + (j * 2) + 1, ']');
      }
    }
  }
}

void fieldPrint(GameInfo_t *game_info) {
  int y = GAME_FIELD_BORDER_BEGIN_Y + 1;
  int x = GAME_FIELD_BORDER_BEGIN_X + 1;

  for (int i = 0; i < GAME_FIELD_HEIGHT; i++) {
    for (int j = 0; j < GAME_FIELD_WIDTH; j++) {
      if (game_info->field[i][j] != 0) {
        mvaddch(y + i, x + (j * 2), '[');
        mvaddch(y + i, x + (j * 2) + 1, ']');
      }
    }
  }
}

void statusWindowPrint(int status) {
  int y1 = BOARD_BORDER_BEGIN_Y + 8;
  int x1 = BOARD_BORDER_BEGIN_X + 10;
  int y2 = y1 + 7;
  int x2 = x1 + 20;

  for (int i = y1; i <= y2; i++) {
    for (int j = x1; j <= x2; j++) {
      mvaddch(i, j, ' ');
    }
  }
  borderPrint(y1, x1, y2, x2);

  switch (status) {
    case START:
      mvprintw(y1 + 2, x1 + 8, "START");
      mvprintw(y1 + 4, x1 + 6, "s - start");
      mvprintw(y1 + 5, x1 + 6, "q - exit");
      break;
    case PAUSE:
      mvprintw(y1 + 2, x1 + 8, "PAUSE");
      mvprintw(y1 + 4, x1 + 6, "p - game");
      mvprintw(y1 + 5, x1 + 6, "q - exit");
      break;
    case GAME_OVER:
      mvprintw(y1 + 2, x1 + 8, "GAME OVER");
      mvprintw(y1 + 4, x1 + 6, "s - restart");
      mvprintw(y1 + 5, x1 + 6, "q - exit");
      break;
  }
}
