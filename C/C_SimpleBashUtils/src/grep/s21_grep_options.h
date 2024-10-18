#ifndef S21_GREP_OPTION_H
#define S21_GREP_OPTION_H

#define _GNU_SOURCE

#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLAGS 10

#define OPT_e 0
#define OPT_i 1
#define OPT_v 2
#define OPT_c 3
#define OPT_l 4
#define OPT_n 5
#define OPT_h 6
#define OPT_s 7
#define OPT_f 8
#define OPT_o 9

typedef struct {
  int number_of_files;
  int number_of_patterns;
  char **list_of_files;
  char **list_of_patterns;
  bool empty_pattern;
  bool active_flags[MAX_FLAGS];
} Options;

typedef struct {
  unsigned int number_of_line;
  unsigned int number_of_matched_lines;
  int regflag;
  char **addressBuffer;
  int number_of_addresses;
} Data_grep;

Options optionsInit();
void optionsFree(Options *);
void optionsParse(int, char **, Options *, Data_grep *);

Data_grep dataInit();
void dataFree(Data_grep *data);

void ifNAndNotH(Options *opt, Data_grep *data, char *filename);
void workO(char *, regex_t *, int, Options *, Data_grep *, char *);
void putS_cl(const char *filename, Options *opt, Data_grep *data);

#endif