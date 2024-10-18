#include "cat_options.h"

struct Options initOptions() {
  struct Options opt;
  opt.active_options_number = 0;

  for (int i = 0; i < MAX_OPTIONS; i++) {
    opt.active_options[i] = false;
  }
  return opt;
}

void shortOptions(char **argv, int i, struct Options *opt) {
  const char *kAllShortOptions[MAX_OPTIONS] = {"-b", "-E", "-n",
                                               "-s", "-T", "-v"};

  int k = 1;

  while (argv[i][k] != '\0') {
    char temp_array[3] = {'-', '\0', '\0'};
    bool option_exists_flag = false;

    temp_array[1] = argv[i][k];
    k++;

    for (int j = 0; j < MAX_OPTIONS; j++) {
      if (strcmp(kAllShortOptions[j], temp_array) == 0) {
        opt->active_options[j] = true;
        opt->active_options_number++;
        option_exists_flag = true;
        break;
      } else if (strcmp("-e", temp_array) == 0) {
        opt->active_options[OPT_E] = true;
        opt->active_options[OPT_v] = true;
        opt->active_options_number = opt->active_options_number + 2;
        option_exists_flag = true;
        break;
      } else if (strcmp("-t", temp_array) == 0) {
        opt->active_options[OPT_T] = true;
        opt->active_options[OPT_v] = true;
        opt->active_options_number = opt->active_options_number + 2;
        option_exists_flag = true;
        break;
      }
    }

    if (option_exists_flag == false) {
      printf("ОШИБКА: Флаг %s не существует!!!\n", temp_array);
      exit(EXIT_FAILURE);
    }
  }
}

void longOptions(char **argv, int i, struct Options *opt) {
  bool option_exists_flag = false;
  const char *kAllLongOptions[MAX_OPTIONS] = {
      "--number-nonblank", "", "--number", "--squeeze-blank", "", ""};

  for (int j = 0; j < MAX_OPTIONS; j++) {
    if (strcmp(kAllLongOptions[j], argv[i]) == 0) {
      opt->active_options[j] = true;
      opt->active_options_number++;
      option_exists_flag = true;
      break;
    }
  }

  if (option_exists_flag == false) {
    printf("ОШИБКА: Флаг %s не существует!!!\n", argv[i]);
    exit(EXIT_FAILURE);
  }
}

struct Options findOptions(int argc, char **argv) {
  struct Options opt;

  opt = initOptions();

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] != '-') {
      shortOptions(argv, i, &opt);

    } else if (argv[i][0] == '-' && argv[i][1] == '-') {
      longOptions(argv, i, &opt);
    }
  }

  // Если есть флаг "-b" и "-n", то работает только "-b"
  if (opt.active_options[OPT_b] == true && opt.active_options[OPT_n] == true) {
    opt.active_options[OPT_n] = false;
    opt.active_options_number--;
  }

  return opt;
}

void workN(unsigned char ch) {
  static int line_flag = 0;

  if (line_flag == 0) {
    static int line_number = 1;
    printf("%6d\t", line_number);
    line_number++;
  }

  if (ch != '\n') {
    line_flag++;
  } else {
    line_flag = 0;
  }
}

void workB(unsigned char ch) {
  static int line_flag = 0;

  if (line_flag == 0 && ch != '\n') {
    static int line_number = 1;
    printf("%6d\t", line_number);
    line_number++;
  }

  if (ch != '\n') {
    line_flag++;
  } else {
    line_flag = 0;
  }
}

bool workS(const int *ch) {
  static int line_flag = 0;
  static int empty_line_flag = 0;

  if (line_flag == 0) {
    if (*ch == '\n') {
      empty_line_flag++;
    } else {
      empty_line_flag = 0;
    }
  }

  if (*ch != '\n') {
    line_flag++;
  } else {
    line_flag = 0;
  }

  if (empty_line_flag > 1 && *ch == '\n')
    return true;
  else
    return false;
}

void workV(int *ch) {
  if (*ch >= 256) {
    *ch = *ch % 256;
  }

  if (*ch >= 0 && *ch < 32) {
    if (*ch != '\t' && *ch != '\n') {
      putchar('^');
      *ch = *ch + 64;
    }
  } else if (*ch == 127) {
    putchar('^');
    *ch = '?';
  } else if (*ch >= 128 && *ch < 160) {
    printf("M-^");
    *ch = *ch - 128 + 64;
  } else if (*ch >= 160 && *ch < 255) {
    printf("M-");
    *ch = *ch - 128;
  } else if (*ch == 255) {
    printf("M-^");
    *ch = '?';
  }
}

void workBigE(unsigned char ch) {
  if (ch == '\n') {
    putchar('$');
  }
}

void workBigT(int *ch) {
  if (*ch == '\t') {
    putchar('^');
    *ch = 'I';
  }
}

bool selectedOptions(int *ch, struct Options *opt) {
  if (opt->active_options[OPT_s] == true) {
    if (workS(ch)) return true;
  }

  if (opt->active_options[OPT_n] == true) {
    workN(*ch);
  }

  if (opt->active_options[OPT_b] == true) {
    workB(*ch);
  }

  if (opt->active_options[OPT_E] == true) {
    workBigE(*ch);
  }

  if (opt->active_options[OPT_v] == true) {
    workV(ch);
  }

  if (opt->active_options[OPT_T] == true) {
    workBigT(ch);
  }

  return false;
}