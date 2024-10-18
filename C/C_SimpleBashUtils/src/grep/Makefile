
WWW = -Wall -Wextra -Werror

s21_grep: s21_grep.c s21_grep_options.c
	gcc $(WWW) s21_grep.c s21_grep_options.c -o s21_grep

test:
	valgrind  --leak-check=full ./s21_grep life text1.txt
	valgrind  --leak-check=full ./s21_grep -i life text1.txt text_eng.txt
	valgrind  --leak-check=full ./s21_grep -e life text1.txt text_eng.txt
	valgrind  --leak-check=full ./s21_grep -c life text1.txt text_eng.txt
	valgrind  --leak-check=full ./s21_grep -n life text1.txt text_eng.txt
	valgrind  --leak-check=full ./s21_grep -v life text1.txt text_eng.txt
	valgrind  --leak-check=full ./s21_grep -l life text1.txt text_eng.txt
	valgrind  --leak-check=full ./s21_grep -s life text1.txt text_eng.txt
	valgrind  --leak-check=full ./s21_grep -h life text1.txt text_eng.txt
	valgrind  --leak-check=full ./s21_grep -o life text1.txt text_eng.txt
	valgrind  --leak-check=full ./s21_grep -f pattern_file text1.txt text_eng.txt

clean:
	rm -rf s21_grep
	rm -rf temp*

check_all:
	clang-format -n *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c 