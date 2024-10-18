#include "s21_grep_options.h"

Options optionsInit() {
  Options opt;

  opt.number_of_files = opt.number_of_patterns = 0;
  opt.list_of_files = opt.list_of_patterns = NULL;
  opt.empty_pattern = false;

  for (int i = 0; i < MAX_FLAGS; i++) {
    opt.active_flags[i] = false;
  }

  return opt;
}

void optionsFree(Options *opt) {
  if (opt->list_of_files) {
    free(opt->list_of_files);
    opt->list_of_files = NULL;
  }

  for (int i = 0; i < opt->number_of_patterns; i++) {
    if (opt->list_of_patterns[i]) {
      opt->list_of_patterns[i] = NULL;
    }
  }

  if (opt->list_of_patterns) {
    free(opt->list_of_patterns);
    opt->list_of_patterns = NULL;
  }
}

char *add_pattern_list(char *buf, Options *opt, Data_grep *data,
                       bool alloc_flag) {
  bool pat_exist_flag = false;

  for (int j = 0; j < opt->number_of_patterns; j++) {
    if (strcmp(opt->list_of_patterns[j], buf) == 0) {
      pat_exist_flag = true;
    }
  }

  if (!pat_exist_flag) {
    opt->number_of_patterns++;
    opt->list_of_patterns = (char **)realloc(
        opt->list_of_patterns, sizeof(char *) * opt->number_of_patterns);
    opt->list_of_patterns[opt->number_of_patterns - 1] = buf;
    if (alloc_flag) {
      data->number_of_addresses++;
      data->addressBuffer = (char **)realloc(
          data->addressBuffer, sizeof(char *) * data->number_of_addresses);
      data->addressBuffer[data->number_of_addresses - 1] = buf;
      buf = NULL;
    }
  }
  return buf;
}

void flagE(int argc, char **argv, Options *opt, Data_grep *data, int *i) {
  if (argv[*i][0] == '-' && strchr(argv[*i], 'e')) {
    *i = *i + 1;
    if (*i >= argc) {
      fprintf(stderr, "ОШИБКА: Флагу \"-e\" нужен аргумент-значение!!!\n");
      exit(EXIT_FAILURE);
    }

    add_pattern_list(argv[*i], opt, data, false);
  }
}

void ifEmptyPatternFile(Options *opt) {
  if (opt->number_of_patterns == 0) {
    // optionsFree(opt);
    exit(EXIT_SUCCESS);
  }
}
void flagF(int argc, char **argv, Options *opt, Data_grep *data) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && strchr(argv[i], 'f') && (i == (argc - 1))) {
      fprintf(stderr, "ОШИБКА: Флагу \"-f\" нужен аргумент-значение!!!\n");
      exit(EXIT_FAILURE);
    }

    if ((argv[i][0] != '-') && argv[i - 1][0] == '-' &&
        strchr(argv[i - 1], 'f')) {
      FILE *fp = fopen(argv[i], "r");
      if (fp == NULL) {
        fprintf(stderr, "%s: ОШИБКА: Файла с таким именем несуществует!!!\n",
                argv[i]);
        exit(EXIT_FAILURE);
      }

      char *buf = NULL;
      size_t buf_size = 50;

      while (getline(&buf, &buf_size, fp) != -1) {
        char *ch;
        if ((ch = strchr(buf, '\n'))) {
          *ch = '\0';
          ch = NULL;
        }

        buf = add_pattern_list(buf, opt, data, true);
      }
      if (buf) {
        free(buf);
        buf = NULL;
      }
      fclose(fp);
    }
  }

  ifEmptyPatternFile(opt);
}

void optionsParse(int argc, char **argv, Options *opt, Data_grep *data) {
  const char *kEasyOptionsList[MAX_FLAGS] = {"-e", "-i", "-v", "-c", "-l",
                                             "-n", "-h", "-s", "-f", "-o"};

  for (int i = 1; i < argc; i++) {
    int k = 1;
    while (argv[i][0] == '-' && argv[i][1] != '\0' && argv[i][k] != '\0') {
      char temp[] = {'-', argv[i][k], '\0'};

      for (int j = 0; j < MAX_FLAGS; j++) {
        if (strcmp(kEasyOptionsList[j], temp) == 0) {
          opt->active_flags[j] = true;
        }
      }
      k++;
    }
    flagE(argc, argv, opt, data, &i);
  }

  if (opt->active_flags[OPT_f]) {
    flagF(argc, argv, opt, data);
  }

  for (int i = 1; i < argc; i++) {
    if (opt->number_of_patterns == 0 && argv[i][0] != '-' &&
        !opt->active_flags[OPT_f] && !opt->active_flags[OPT_e]) {
      opt->number_of_patterns++;
      opt->list_of_patterns =
          (char **)malloc(sizeof(char *) * opt->number_of_patterns);
      opt->list_of_patterns[opt->number_of_patterns - 1] = argv[i];
      continue;
    }

    if (opt->number_of_patterns >= 1 && argv[i][0] != '-' &&
        (argv[i - 1][0] != '-' ||
         (!strchr(argv[i - 1], 'e') && !strchr(argv[i - 1], 'f')))) {
      opt->number_of_files++;
      opt->list_of_files = (char **)realloc(
          opt->list_of_files, sizeof(char *) * opt->number_of_files);
      opt->list_of_files[opt->number_of_files - 1] = argv[i];
    }
  }
}

Data_grep dataInit() {
  Data_grep data;
  data.number_of_line = data.number_of_matched_lines = 0;
  data.regflag = REG_EXTENDED;
  data.addressBuffer = NULL;
  data.number_of_addresses = 0;

  return data;
}

void dataFree(Data_grep *data) {
  for (int i = 0; i < data->number_of_addresses; i++) {
    if (data->addressBuffer[i]) {
      free(data->addressBuffer[i]);
      data->addressBuffer[i] = NULL;
    }
  }

  if (data->addressBuffer) {
    free(data->addressBuffer);
    data->addressBuffer = NULL;
  }
}

void ifNAndNotH(Options *opt, Data_grep *data, char *filename) {
  if (opt->number_of_files > 1 && !opt->active_flags[OPT_h]) {
    printf("%s:", filename);
  }

  if (opt->active_flags[OPT_n]) {
    printf("%u:", data->number_of_line);
  }
}

void workO(char *buf, regex_t *reg, int j, Options *opt, Data_grep *data,
           char *filename) {
  regmatch_t match;

  if (!opt->active_flags[OPT_c] && !opt->active_flags[OPT_l]) {
    while (j < opt->number_of_patterns) {
      while (regexec(&reg[j], buf, 1, &match, 0) == 0) {
        ifNAndNotH(opt, data, filename);

        printf("%.*s\n", (int)(match.rm_eo - match.rm_so), buf + match.rm_so);
        buf += match.rm_eo;
      }
      j++;
    }
  }
}

void putS_cl(const char *filename, Options *opt, Data_grep *data) {
  if (opt->active_flags[OPT_l]) {
    if (opt->active_flags[OPT_l] && data->number_of_matched_lines > 0) {
      printf("%s\n", filename);
    }
  } else if (opt->active_flags[OPT_c]) {
    if (opt->number_of_files > 1 && !opt->active_flags[OPT_h]) {
      printf("%s:", filename);
    }

    printf("%u\n", data->number_of_matched_lines);
  }
}