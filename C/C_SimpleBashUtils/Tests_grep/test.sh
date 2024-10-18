#!/bin/bash

number_of_tests=0
number_of_failures=0
number_of_successes=0

file="text1.txt"
list_of_files="text1.txt empty.txt text_eng.txt lines.txt"
patterns="fds l[ift][gf]e lIfE"
list_of_flags="-n -c -l -v -i -e -h -o"

echo -e "\n==============================================================="
echo "================ Общии тесты ========================"
echo -e "===============================================================\n"

#Тест пустой шаблон
((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Один файл - без флага - Паттерн \"\" =="

grep "" $file >temp1.txt
./s21_grep "" $file >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

#----------------------------
((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколько файлов - без флага - Паттерн \"\" =="

grep "" $list_of_files >temp1.txt
./s21_grep "" $list_of_files >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi
#Без флагов
for var in $patterns; do
    ((number_of_tests++))
    echo -e ">>> ТЕСТ $number_of_tests <<< : == Один файл - без флага - Паттерн \"$var\" =="

    grep $var $file >temp1.txt
    ./s21_grep $var $file >temp2.txt
    if diff -q temp1.txt temp2.txt; then
        echo -e "\t\t\t\t\t\t----- SUCCESS -----"
        ((number_of_successes++))
    else
        echo -e "\t\t\t\t\t\t----- FAILURE -----"
        ((number_of_failures++))
    fi
done

for var in $patterns; do
    ((number_of_tests++))
    echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколько файлов - без флага - Паттерн \"$var\" =="

    grep $var $list_of_files >temp1.txt
    ./s21_grep $var $list_of_files >temp2.txt
    if diff -q temp1.txt temp2.txt; then
        echo -e "\t\t\t\t\t\t----- SUCCESS -----"
        ((number_of_successes++))
    else
        echo -e "\t\t\t\t\t\t----- FAILURE -----"
        ((number_of_failures++))
    fi
done

#Тесты с флагами
for flag in $list_of_flags; do
    ((number_of_tests++))
    echo -e ">>> ТЕСТ $number_of_tests <<< : == Один файл - Флаг \"$flag\" - Паттерн \"\" =="

    grep $flag "" $file >temp1.txt
    ./s21_grep $flag "" $file >temp2.txt
    if diff -q temp1.txt temp2.txt; then
        echo -e "\t\t\t\t\t\t----- SUCCESS -----"
        ((number_of_successes++))
    else
        echo -e "\t\t\t\t\t\t----- FAILURE -----"
        ((number_of_failures++))
    fi

    #----------------------------
    ((number_of_tests++))
    echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколько файлов - Флаг \"$flag\" - Паттерн \"\" =="

    grep $flag "" $list_of_files >temp1.txt
    ./s21_grep $flag "" $list_of_files >temp2.txt
    if diff -q temp1.txt temp2.txt; then
        echo -e "\t\t\t\t\t\t----- SUCCESS -----"
        ((number_of_successes++))
    else
        echo -e "\t\t\t\t\t\t----- FAILURE -----"
        ((number_of_failures++))
    fi

    #Без флагов
    for var in $patterns; do
        ((number_of_tests++))
        echo -e ">>> ТЕСТ $number_of_tests <<< : == Один файл - Флаг \"$flag\" - Паттерн \"$var\" =="

        grep $flag $var $file >temp1.txt
        ./s21_grep $flag $var $file >temp2.txt
        if diff -q temp1.txt temp2.txt; then
            echo -e "\t\t\t\t\t\t----- SUCCESS -----"
            ((number_of_successes++))
        else
            echo -e "\t\t\t\t\t\t----- FAILURE -----"
            ((number_of_failures++))
        fi
    done

    for var in $patterns; do
        ((number_of_tests++))
        echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколько файлов - Флаг \"$flag\" - Паттерн \"$var\" =="

        grep $flag $var $list_of_files >temp1.txt
        ./s21_grep $flag $var $list_of_files >temp2.txt
        if diff -q temp1.txt temp2.txt; then
            echo -e "\t\t\t\t\t\t----- SUCCESS -----"
            ((number_of_successes++))
        else
            echo -e "\t\t\t\t\t\t----- FAILURE -----"
            ((number_of_failures++))
        fi
    done

done

#Флаг -e несколько шаблонов
((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Один файл - Флаг \"-e\" - Два Паттерна =="

grep -e life -e -n $file >temp1.txt
./s21_grep -e life -e -n $file >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколко файлов - Флаг \"-e\" - Два Паттерна =="

grep -e life -e -n $list_of_files >temp1.txt
./s21_grep -e life -e -n $list_of_files >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколко файлов - Флаг \"-e\" - Три Паттерна (два одинаковых) =="

grep -e life -e -n -e life $list_of_files >temp1.txt
./s21_grep -e life -e -n -e life $list_of_files >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколко файлов - Флаг \"-e и -v\"  - Два Паттерна =="

grep -v -e -n -e life $list_of_files >temp1.txt
./s21_grep -v -e -n -e life $list_of_files >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

#Флаг -s
((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколко файлов (Один файл несуществует!) - Флаг \"-s\"  - Один Паттерн  =="

grep -s life $file not_exsist.txt >temp1.txt
./s21_grep -s life $file not_exsist.txt >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколко файлов (Один файл несуществует!) - Флаг \"-s и -e\"  - Один Паттерн  =="

grep -s life -e sd $file not_exsist.txt >temp1.txt
./s21_grep -s life -e sd $file not_exsist.txt >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

#Флаг -f
((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколко файлов - Флаг \"-f\"  - Несколько Паттернов в файле (есть одинаковые)  =="

grep -f pattern_file.txt $list_of_files >temp1.txt
./s21_grep -f pattern_file.txt $list_of_files >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколко файлов - Флаг \"-f\"  - Файл с шаблонами ПУСТОЙ  =="

grep -f empty.txt $list_of_files >temp1.txt
./s21_grep -f empty.txt $list_of_files >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Несколко файлов - Флаг \"-f и -e\"  - Несколько Паттернов в файле (есть одинаковые)  =="

grep -e long -f pattern_file.txt $list_of_files >temp1.txt
./s21_grep -e long -f pattern_file.txt $list_of_files >temp2.txt
if diff -q temp1.txt temp2.txt; then
    echo -e "\t\t\t\t\t\t----- SUCCESS -----"
    ((number_of_successes++))
else
    echo -e "\t\t\t\t\t\t----- FAILURE -----"
    ((number_of_failures++))
fi

echo -e "\n==============================================================="
echo "================ ПАРНЫЕ ФЛАГИ ========================"
echo -e "===============================================================\n"

#Флаг Парные слитно написанные
# -e.. grep работает с ошибкой
list_of_flags="-n -c -l -v -i -h -o"
list="n c l v i e h o"
for var in $patterns; do
    for var1 in $list_of_flags; do
        for var2 in $list; do
            ((number_of_tests++))
            echo -e ">>> ТЕСТ $number_of_tests <<< : == Один файл - Два флага слитно "$var1$var2" - Паттерн \"$var\" =="

            grep "$var1$var2" $var $file >temp1.txt
            ./s21_grep "$var1$var2" $var $file >temp2.txt
            if diff -q temp1.txt temp2.txt; then
                echo -e "\t\t\t\t\t\t----- SUCCESS -----"
                ((number_of_successes++))
            else
                echo -e "\t\t\t\t\t\t----- FAILURE -----"
                ((number_of_failures++))
            fi
        done
    done
done

for var in $patterns; do
    for var1 in $list_of_flags; do
        for var2 in $list; do
            ((number_of_tests++))
            echo -e ">>> ТЕСТ $number_of_tests <<< : == Один файл - Два флага слитно "$var1$var2" - Паттерн \"$var\" =="

            grep "$var1$var2" $var $list_of_files >temp1.txt
            ./s21_grep "$var1$var2" $var $list_of_files >temp2.txt
            if diff -q temp1.txt temp2.txt; then
                echo -e "\t\t\t\t\t\t----- SUCCESS -----"
                ((number_of_successes++))
            else
                echo -e "\t\t\t\t\t\t----- FAILURE -----"
                ((number_of_failures++))
            fi
        done
    done
done

echo "Общее количество автоматизированных тестов: $number_of_tests"
echo "Общее количество FAILURES: $number_of_failures"
echo "Общее количество SUCCESSES: $number_of_successes"
echo

echo -e "\n==============================================================="
echo "================ РЕЗУЛЬТАТ ЧИТАТЬ ========================"
echo -e "===============================================================\n"

number_of_tests=0

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Без шаблона и без файла \"./s21_grep  \" =="
grep
./s21_grep
echo

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Без файла (stdin) \"./s21_grep life\" =="
./s21_grep life
echo

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Без файла (stdin) \"./s21_grep -e life\" =="
./s21_grep -e life
echo

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == Без файла и неществующий файл с шаблонами \"./s21_grep -f life\" =="
grep -f life
./s21_grep -f life
echo

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == \"./s21_grep life -e\" =="
grep life -e
./s21_grep life -e
echo

((number_of_tests++))
echo -e ">>> ТЕСТ $number_of_tests <<< : == \"./s21_grep life -f\"  =="
grep life -f
./s21_grep life -f
echo
