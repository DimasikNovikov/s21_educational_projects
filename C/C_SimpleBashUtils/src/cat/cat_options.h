#ifndef CAT_OPTIONS_H
#define CAT_OPTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPTIONS 6

#define OPT_b 0
#define OPT_E 1
#define OPT_n 2
#define OPT_s 3
#define OPT_T 4
#define OPT_v 5

struct Options {
  int active_options_number;
  bool active_options[MAX_OPTIONS];
};

struct Options initOptions();
struct Options findOptions(int, char **);
void shortOptions(char **argv, int i, struct Options *opt);
void longOptions(char **argv, int i, struct Options *opt);

bool selectedOptions(int *ch, struct Options *opt);
void workN(unsigned char ch);
void workB(unsigned char ch);
bool workS(const int *ch);
void workV(int *ch);
void workBigE(unsigned char ch);
void workBigT(int *ch);

#endif