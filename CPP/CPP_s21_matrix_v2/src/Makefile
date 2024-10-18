CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17


all: s21_matrix_oop.a test

s21_matrix_oop.o: s21_matrix_oop.cpp
	$(CXX) -c s21_matrix_oop.cpp

s21_matrix_oop.a: s21_matrix_oop.o
	ar rc s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a


test: s21_matrix_oop.a test_s21_matrix_oop.cpp
	$(CXX) $(CXXFLAGS) test_s21_matrix_oop.cpp s21_matrix_oop.a -o test -lgtest


gcov_report: test_s21_matrix_oop.cpp s21_matrix_oop.cpp
	$(CXX) $(CXXFLAGS) --coverage test_s21_matrix_oop.cpp s21_matrix_oop.cpp -o test -lgtest
	./test
	lcov -t test -o coverage.info -c -d .
	genhtml -o report coverage.info


clean:
	rm -f s21_matrix_oop.a s21_matrix_oop.o
	rm -f *.gcda *.gcno *.info
	rm -fr report
	rm test valgrind.log

valgrind:
	valgrind --leak-check=full --undef-value-errors=yes --track-origins=yes --show-reachable=yes -s --log-file=valgrind.log ./test
	grep 'ERROR SUMMARY' valgrind.log
