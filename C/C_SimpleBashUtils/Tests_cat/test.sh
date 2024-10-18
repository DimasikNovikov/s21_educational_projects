#!/bin/bash

number_of_tests=0
number_of_failures=0
number_of_successes=0

list_of_flags="-b -e -n -s -t -v -E -T --number-nonblank --number --squeeze-blank"
list_of_files="rand1.txt empty.txt lines.txt rand2.txt"
file="rand1.txt"

# list_of_files="text_eng.txt text_rus.txt text1.txt"
# file="text_eng.txt"

#Тесты с одним файлом
echo -e "\n==============================================================="
echo "================ АВТОМАТИЗИРОВАННЫЕ ТЕСТЫ ========================"
echo -e "===============================================================\n"

for var in " " $list_of_flags "$list_of_flags" "-nbest"
do

    ((number_of_tests++))
    echo -e ">>> ТЕСТ $number_of_tests <<< : == Один файл - флаг \"$var\" =="

    cat $var $file > temp1.txt
    ./s21_cat $var $file > temp2.txt
    if diff -q temp1.txt temp2.txt
    then
        echo -e "\t\t\t\t\t\t----- SUCCESS -----"
        ((number_of_successes++))
    else
        echo -e "\t\t\t\t\t\t----- FAILURE -----"
        ((number_of_failures++))
    fi        
done

for var in " " $list_of_flags "$list_of_flags" "-nbest"
do

    ((number_of_tests++))
    echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколько файлов - флаг \"$var\" =="

    cat $var $list_of_files > temp1.txt
    ./s21_cat $var $list_of_files > temp2.txt
    if diff -q temp1.txt temp2.txt
    then
        echo -e "\t\t\t\t\t\t----- SUCCESS -----"
        ((number_of_successes++))
    else
        echo -e "\t\t\t\t\t\t----- FAILURE -----"
        ((number_of_failures++))
    fi        
done


#Тесты без файлов, флагов и некорректные
echo -e "\n==============================================================="
echo "================ РУЧНЫЕ ТЕСТЫ ========================"
echo -e "===============================================================\n"

echo -e "\t\t>>> ТЕСТ: == без файла == <<<"
echo "(В оригинале клавиатурный ввод в stdio)"
./s21_cat
echo -e "\n"

echo -e "\t\t>>> ТЕСТ: == только - == <<<"
echo "(В оригинале клавиатурный ввод в stdio)"
./s21_cat -
echo -e "\n"

var2="-f"
echo -e "\t\t>>> ТЕСТ: == Несуществующий флаг - \"$var2\" == <<<"
echo "./s21_cat $var2 $file"
./s21_cat $var2 $file
echo
echo "cat $var2 $file"
cat $var2 $file
echo -e "\n"

var2="-nbefst"
echo -e "\t\t>>> ТЕСТ: == Несуществующий флаг в последовательности - \"$var2\" == <<<"
echo "./s21_cat $var2 $file"
./s21_cat $var2 $file
echo
echo "cat $var2 $file"
cat $var2 $file
echo -e "\n"

file="twix.txt"
echo -e "\t\t>>> ТЕСТ: == Несуществующий Файл - \"$file\" == <<<"
echo "./s21_cat $file"
./s21_cat $file
echo
echo "cat $file"
cat $file
echo -e "\n"

#Закомментил потому что тест занимает много места на экране, а по diff сравнить не получится, т.к. текст ошибок разный

# file="rand1.txt lines.txt twix.txt rand2.txt"
# echo -e "\t\t>>> ТЕСТ: == Несуществующий Файл среди нескольких файлов == <<<"
# echo "./s21_cat $file"
# ./s21_cat $file
# echo
# echo "cat $file"
# cat $file
# echo -e "\n\n"


echo "Общее количество автоматизированных тестов: $number_of_tests"
echo "Общее количество FAILURES: $number_of_failures"
echo "Общее количество SUCCESSES: $number_of_successes"
echo


