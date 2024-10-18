CC = gcc
CFLAGS = -I brick_game/tetris -I gui/cli -Wall -Wextra -Werror -std=gnu11
CHECK_LFLAGS = -lcheck -lm -lsubunit
#TEMPCFLAGS = -fsanitize=address -fsanitize=undefined
SOURCE_BACK = $(wildcard brick_game/tetris/*.c)
SOURCE_FRONT = gui/cli/frontend.c
SOURCE = $(SOURCE_BACK) $(SOURCE_FRONT) game/game.c


all: install

install: $(SOURCE)
	$(CC) $(CFLAGS) $^ -o game_tetris -lncurses

uninstall:
	rm -f game_tetris
	rm -f high_score.txt

clean:
	rm -f test_tetris_game* coverage.info
	rm -f valgrind.log high_score.txt game_log.txt
	rm -f tetris_admiralm.tar.gz
	rm -rf ./doxygen 
	rm -rf ./report

dvi:
	doxygen Doxyfile

dist:
	tar -czvf tetris_admiralm.tar.gz ./brick_game/tetris/ ./game/ ./gui/cli/

checkmk:
	checkmk clean_mode=1 tests.check > test_tetris_game.c

test: checkmk $(SOURCE_BACK)
	$(CC) $(CFLAGS) -g $(SOURCE_BACK) test_tetris_game.c -o test_tetris_game $(CHECK_LFLAGS)

gcov_report: checkmk $(SOURCE_BACK)
	$(CC) $(CFLAGS) -g --coverage $(SOURCE_BACK) test_tetris_game.c -o test_tetris_game $(CHECK_LFLAGS)
	./test_tetris_game
	lcov -o coverage.info -c -d .
	genhtml -o report coverage.info

valgrind:
	valgrind --leak-check=full --undef-value-errors=yes --track-origins=yes --show-reachable=yes -s --log-file=valgrind.log ./test_tetris_game
	grep 'ERROR SUMMARY' valgrind.log