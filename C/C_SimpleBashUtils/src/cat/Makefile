
WWW = -Wall -Wextra -Werror

s21_cat: cat_options.c s21_cat.c
	gcc $(WWW) cat_options.c s21_cat.c -o s21_cat

clean:
	rm -rf s21_cat
	rm -rf temp*

check_all:
	clang-format -n *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c 