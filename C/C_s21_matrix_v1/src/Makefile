CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TEMPCFLAGS = -fsanitize=address -fsanitize=undefined

SOURCE = extra.c $(wildcard s21*.c)
OBJ = $(SOURCE:.c=.o)
TESTS = $(wildcard Tests/*.check)
LFLAGS = -lcheck -lm -lsubunit

all: s21_matrix.a test

$(OBJ): %.o: %.c

s21_matrix.a: $(OBJ)
	ar rc s21_matrix.a $(OBJ)
	ranlib s21_matrix.a

test: checkmk s21_matrix.a
	$(CC) $(CFLAGS) test_matrix.c s21_matrix.a $(LFLAGS) -o test
	./test

checkmk: $(TESTS)
	checkmk clean_mode=1 $(TESTS) > test_matrix.c

clean:
	rm -f *.o test s21_matrix.a test_matrix* valgrind.log
	rm -rf report
	rm -f *.gcda *.gcno *.info


gcov_report: checkmk $(SOURCE)
	$(CC) $(CFLAGS) --coverage test_matrix.c $(SOURCE) $(LFLAGS) -o test
	./test
	lcov -o coverage.info -c -d .
	genhtml -o report coverage.info

valgrind:
	valgrind --leak-check=full --undef-value-errors=yes --track-origins=yes --show-reachable=yes -s --log-file=valgrind.log ./test
	grep 'ERROR SUMMARY' valgrind.log
	