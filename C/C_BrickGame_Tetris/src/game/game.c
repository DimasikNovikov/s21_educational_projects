/**
 * @file game.c
 * Файл для сведения Фронтенд и Бекенд частей.
 *
 * @author admiralm
 * @version 1
 * @date 2024-06-29
 */

#include "backend.h"
#include "frontend.h"

void game_loop();
void interpretInput(int ch);

int main() {
  ncursesTurnOn();
  game_loop();
  endwin();
  return 0;
}

/**
 * @brief game_loop
 * Игровой цикл. Ядро игры.
 */
void game_loop() {
  initGame();
  GameInfo_t game_info = updateCurrentState();

  while (game_info.pause != EXIT && !checkErrorFlag()) {
    boardDisplay(&game_info);

    int ch = getch();
    interpretInput(ch);

    game_info = updateCurrentState();
  }

  deleteGameInfo(&game_info);
}

/**
 * @brief interpretInput
 * Функция интерпретирует нажатие клавиши в действие.
 *
 * @param ch Код нажатой клавиши.
 */
void interpretInput(int ch) {
  switch (ch) {
    case 's':
      userInput(Start, false);
      break;
    case 'p':
      userInput(Pause, false);
      break;
    case 32:
      userInput(Action, false);
      break;
    case KEY_DOWN:
      userInput(Down, false);
      break;
    case KEY_LEFT:
      userInput(Left, false);
      break;
    case KEY_RIGHT:
      userInput(Right, false);
      break;
    case 'q':
      userInput(Terminate, false);
      break;
  }
}