#include "backend.h"

static GameInfo_t game_info;
static bool error_flag = false;
static Figure_t figure_next = {0};
static Figure_t figure_now = {0};
static Figure_t figure_old = {0};

void userInput(UserAction_t action, bool hold) {
  (void)hold;
  switch (action) {
    case Terminate:
      if (game_info.pause == START || game_info.pause == PAUSE ||
          game_info.pause == GAME_OVER) {
        game_info.pause = EXIT;
      }
      break;
    case Start:
      if (game_info.pause == START) {
        generateFigure();
        game_info.pause = BEGIN_POSITION;
      } else if (game_info.pause == GAME_OVER) {
        game_info.pause = START;
      }
      break;
    case Pause:
      if (game_info.pause == MOVEMENT) {
        game_info.pause = PAUSE;
      } else if (game_info.pause == PAUSE) {
        game_info.pause = MOVEMENT;
      }
      break;
    case Right:
      if (game_info.pause == MOVEMENT) {
        moveFigureRight();
      }
      break;
    case Left:
      if (game_info.pause == MOVEMENT) {
        moveFigureLeft();
      }
      break;
    case Action:
      if (game_info.pause == MOVEMENT) {
        rotationFigure();
      }
      break;
    case Down:
      if (game_info.pause == MOVEMENT) {
        while (game_info.pause != END_POSITION) {
          moveFigureDown();
        }
      }
      break;
    case Up:
      break;
  }
}

GameInfo_t updateCurrentState() {
  switch (game_info.pause) {
    case START:
      startStatus();
      break;
    case BEGIN_POSITION:
      beginPositionStatus();
      break;
    case MOVEMENT:
      movementStatus();
      break;
    case END_POSITION:
      endPositionStatus();
      break;
    case GAME_OVER:
      setHighScore();
      break;
  }
  return game_info;
}

//===================== Дополнительные Функции ==================

void initGame() {
  game_info.field = newMatrix(GAME_FIELD_HEIGHT, GAME_FIELD_WIDTH);
  game_info.next = newMatrix(FIGURE_SIZE, FIGURE_SIZE);

  if (game_info.field != NULL && game_info.next != NULL) {
    game_info.pause = START;
  } else {
    error_flag = true;
  }
}

void startStatus() {
  game_info.score = 0;
  game_info.high_score = getHighScore();
  game_info.level = 1;
  game_info.speed = SPEED;  // миллисекунды на пиксель (1500)

  zeroMatrix(GAME_FIELD_HEIGHT, GAME_FIELD_WIDTH, game_info.field);
  zeroMatrix(FIGURE_SIZE, FIGURE_SIZE, game_info.next);
}

void generateFigure() {
  figure_next.x = figure_next.y = 0;

  srand(time(NULL));
  figure_next.name = rand() % 7;

  switch (figure_next.name) {
    case O:
      figure_next.rotation = 0;
      break;
    case I:
    case S:
    case Z:
      figure_next.rotation = rand() % 2;
      break;
    case L:
    case J:
    case T:
      figure_next.rotation = rand() % 4;
      break;
  }

  identifyFigure(&figure_next);

  for (int i = 0; i < FIGURE_SIZE; i++) {
    for (int j = 0; j < FIGURE_SIZE; j++) {
      game_info.next[i][j] = figure_next.matrix[i][j];
    }
  }
}

void beginPositionStatus() {
  figure_now = figure_next;
  figure_now.y = START_POSITION_Y;
  figure_now.x = START_POSITION_X;
  generateFigure();

  for (int i_figure = 0, i_field = figure_now.y; i_figure < FIGURE_SIZE;
       i_figure++, i_field++) {
    for (int j_figure = 0, j_field = figure_now.x; j_figure < FIGURE_SIZE;
         j_figure++, j_field++) {
      if (figure_now.matrix[i_figure][j_figure] == 1 &&
          game_info.field[i_field][j_field] == 2) {
        game_info.pause = GAME_OVER;
        return;
      }
    }
  }

  insertFigureIntoField();

  game_info.pause = MOVEMENT;
}

void eraseFigureFromField() {
  if (game_info.pause == MOVEMENT) {
    for (int i = 0; i < GAME_FIELD_HEIGHT; i++) {
      for (int j = 0; j < GAME_FIELD_WIDTH; j++) {
        if (game_info.field[i][j] == 1) {
          game_info.field[i][j] = 0;
        }
      }
    }
  }
}

void moveFigureRight() {
  bool return_flag = false;

  figure_old = figure_now;
  eraseFigureFromField();

  figure_now.x++;

  for (int i_figure = 0, i_field = figure_now.y;
       i_figure < FIGURE_SIZE && !return_flag; i_figure++, i_field++) {
    for (int j_figure = 0, j_field = figure_now.x;
         j_figure < FIGURE_SIZE && !return_flag; j_figure++, j_field++) {
      if (figure_now.matrix[i_figure][j_figure] == 1) {
        if (j_field >= GAME_FIELD_WIDTH) {
          figure_now = figure_old;
          return_flag = true;
        } else if (game_info.field[i_field][j_field] == 2) {
          figure_now = figure_old;
          return_flag = true;
        }
      }
    }
  }
}

void moveFigureLeft() {
  bool return_flag = false;

  figure_old = figure_now;
  eraseFigureFromField();

  figure_now.x--;

  for (int i_figure = 0, i_field = figure_now.y;
       i_figure < FIGURE_SIZE && !return_flag; i_figure++, i_field++) {
    for (int j_figure = 0, j_field = figure_now.x;
         j_figure < FIGURE_SIZE && !return_flag; j_figure++, j_field++) {
      if (j_field < 0) {
        figure_now = figure_old;
        return_flag = true;
      } else if (figure_now.matrix[i_figure][j_figure] == 1 &&
                 game_info.field[i_field][j_field] == 2 && j_figure == 0) {
        figure_now = figure_old;
        return_flag = true;
      }
    }
  }
}

void moveFigureDown() {
  bool return_flag = false;

  figure_old = figure_now;
  eraseFigureFromField();

  figure_now.y++;

  for (int i_figure = 0, i_field = figure_now.y;
       i_figure < FIGURE_SIZE && !return_flag; i_figure++, i_field++) {
    for (int j_figure = 0, j_field = figure_now.x;
         j_figure < FIGURE_SIZE && !return_flag; j_figure++, j_field++) {
      if (figure_now.matrix[i_figure][j_figure] == 1) {
        if (i_field >= GAME_FIELD_HEIGHT) {
          figure_now = figure_old;
          game_info.pause = END_POSITION;
          return_flag = true;
        } else if (game_info.field[i_field][j_field] == 2) {
          figure_now = figure_old;
          game_info.pause = END_POSITION;
          return_flag = true;
        }
      }
    }
  }
}

void rotationFigure() {
  int attempt = 0;
  bool left_flag = true;
  bool right_flag = true;

  figure_old = figure_now;
  figure_now.rotation++;
  identifyFigure(&figure_now);
  eraseFigureFromField();

  while (left_flag || right_flag) {
    left_flag = false;
    right_flag = false;

    for (int i_figure = 0, i_field = figure_now.y;
         i_figure < FIGURE_SIZE && !left_flag; i_figure++, i_field++) {
      for (int j_figure = 0, j_field = figure_now.x;
           j_figure < FIGURE_SIZE && !left_flag; j_figure++, j_field++) {
        if (j_field < 0) {
          left_flag = true;
        } else if (figure_now.matrix[i_figure][j_figure] == 1 &&
                   game_info.field[i_field][j_field] == 2) {
          left_flag = true;
        }
      }
    }

    for (int i_figure = 0, i_field = figure_now.y;
         i_figure < FIGURE_SIZE && !right_flag; i_figure++, i_field++) {
      for (int j_figure = 0, j_field = figure_now.x;
           j_figure < FIGURE_SIZE && !right_flag; j_figure++, j_field++) {
        if (figure_now.matrix[i_figure][j_figure] == 1) {
          if (j_field >= GAME_FIELD_WIDTH) {
            right_flag = true;
          } else if (game_info.field[i_field][j_field] == 2) {
            right_flag = true;
          }
        }
      }
    }

    if (left_flag && right_flag) {
      figure_now = figure_old;
      return;
    } else if (left_flag) {
      figure_now.x++;
      attempt++;
    } else if (right_flag) {
      figure_now.x--;
      attempt++;
    }

    if (attempt >= 4) {
      figure_now = figure_old;
      return;
    }
  }

  for (int i_figure = 0, i_field = figure_now.y; i_figure < FIGURE_SIZE;
       i_figure++, i_field++) {
    for (int j_figure = 0, j_field = figure_now.x; j_figure < FIGURE_SIZE;
         j_figure++, j_field++) {
      if (figure_now.matrix[i_figure][j_figure] == 1) {
        if (i_field >= GAME_FIELD_HEIGHT) {
          figure_now = figure_old;
          return;
        } else if (game_info.field[i_field][j_field] == 2) {
          figure_now = figure_old;
          return;
        }
      }
    }
  }
}

void insertFigureIntoField() {
  for (int i_field = figure_now.y, i_figure = 0; i_figure < FIGURE_SIZE;
       i_field++, i_figure++) {
    for (int j_field = figure_now.x, j_figure = 0; j_figure < FIGURE_SIZE;
         j_field++, j_figure++) {
      if (game_info.pause == END_POSITION) {
        if (figure_now.matrix[i_figure][j_figure] == 1 &&
            game_info.field[i_field][j_field] == 0) {
          game_info.field[i_field][j_field] = 2;
        }
      } else if (figure_now.matrix[i_figure][j_figure] == 1 &&
                 game_info.field[i_field][j_field] == 0) {
        game_info.field[i_field][j_field] = 1;
      }
    }
  }
}

void movementStatus() {
  static struct timespec start, end;
  static bool timer_flag = true;

  if (timer_flag) {
    clock_gettime(CLOCK_MONOTONIC, &start);
  }
  insertFigureIntoField();
  clock_gettime(CLOCK_MONOTONIC, &end);
  //миллисекунды
  long diff_time = (end.tv_sec - start.tv_sec) * 1000 +
                   (end.tv_nsec - start.tv_nsec) / 1000000;

  if (diff_time >= game_info.speed) {
    moveFigureDown();
    timer_flag = true;
  } else {
    timer_flag = false;
  }
}

void endPositionStatus() {
  bool empty_line_flag = false;
  int erased_lines = 0;

  insertFigureIntoField();

  for (int i = GAME_FIELD_HEIGHT - 1; i >= 0 && !empty_line_flag;) {
    empty_line_flag = true;
    int full_line = 0;
    for (int j = 0; j < GAME_FIELD_WIDTH; j++) {
      if (game_info.field[i][j] == 2) {
        empty_line_flag = false;
        full_line++;
      }
    }
    if (full_line == GAME_FIELD_WIDTH) {
      for (int k = i; k > 0; k--) {
        for (int l = 0; l < GAME_FIELD_WIDTH; l++) {
          game_info.field[k][l] = game_info.field[k - 1][l];
        }
      }
      for (int l = 0; l < GAME_FIELD_WIDTH; l++) {
        game_info.field[0][l] = 0;
      }

      erased_lines++;
    } else {
      i--;
    }
  }

  calculateScore(erased_lines);

  game_info.pause = BEGIN_POSITION;
}

void calculateScore(int number_erased_lines) {
  switch (number_erased_lines) {
    case 0:
      break;
    case 1:
      game_info.score += 100;
      break;
    case 2:
      game_info.score += 300;
      break;
    case 3:
      game_info.score += 700;
      break;
    default:
      game_info.score += 1500;
      break;
  }

  if (game_info.score > game_info.high_score) {
    game_info.high_score = game_info.score;
  }

  if (game_info.level < 10) {
    game_info.level = game_info.score / 600 + 1;
  }
  game_info.speed = SPEED - ((game_info.level - 1) * 50);
}

int **newMatrix(int rows, int columns) {
  int **matrix = (int **)malloc(sizeof(int *) * rows);
  if (matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      matrix[i] = (int *)malloc(sizeof(int) * columns);
      if (matrix[i] == NULL) {
        error_flag = true;
        for (int j = 0; j < i; j++) {
          free(matrix[j]);
        }
        free(matrix);
      }
    }

  } else {
    error_flag = true;
  }

  if (error_flag) {
    gameLog("ERROR: newMatrix: Memory allocation problem!");
  }

  return matrix;
}

void zeroMatrix(int rows, int columns, int **matrix) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = 0;
    }
  }
}

void deleteMatrix(int rows, int **matrix) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
    matrix[i] = NULL;
  }
  free(matrix);
  matrix = NULL;
}

void deleteGameInfo(GameInfo_t *g_info) {
  deleteMatrix(GAME_FIELD_HEIGHT, g_info->field);
  deleteMatrix(FIGURE_SIZE, g_info->next);
}

int getHighScore() {
  int highScore = 0;

  FILE *file = fopen("high_score.txt", "rb");
  if (file != NULL) {
    fread(&highScore, sizeof(int), 1, file);
  }
  if (file) {
    fclose(file);
  }

  return highScore;
}

void setHighScore() {
  FILE *file = fopen("high_score.txt", "wb");
  if (file != NULL) {
    fwrite(&game_info.high_score, sizeof(int), 1, file);
  }
  if (file) {
    fclose(file);
  }
}

bool checkErrorFlag() { return error_flag; }

void gameLog(char *str) {
  time_t my_time = time(NULL);
  struct tm *now = localtime(&my_time);

  FILE *file = fopen("game_log.txt", "a");
  if (file != NULL) {
    fprintf(file, "%d.%d.%d %d:%d:%d\n", now->tm_mday, now->tm_mon + 1,
            now->tm_year + 1900, now->tm_hour, now->tm_min, now->tm_sec);
    fprintf(file, "%s\n", str);
  }

  if (file) {
    fclose(file);
  }
}

//====================== Functions for Testing Program =============
Figure_t funcForTestFigureNow() { return figure_now; }
Figure_t funcForTestFigureNext() { return figure_next; }