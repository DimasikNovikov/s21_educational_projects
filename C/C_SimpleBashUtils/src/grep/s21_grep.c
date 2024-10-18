#include "s21_grep_options.h"

void firstErrorCheck(Options *);
void checkSomeFlags(Options *);
void regError(int, const regex_t *);
void getFile(int i, regex_t *, FILE *, Options *, Data_grep *);
void putS(char *, char *, Options *, Data_grep *);

int main(int argc, char *argv[]) {
  Options opt = optionsInit();
  Data_grep data = dataInit();
  optionsParse(argc, argv, &opt, &data);

  firstErrorCheck(&opt);

  FILE *fp = NULL;
  regex_t reg[opt.number_of_patterns];

  for (int i = 0; i < opt.number_of_patterns; i++) {
    if (opt.list_of_patterns[i][0] == '\0') {
      opt.empty_pattern = true;
    }
  }

  checkSomeFlags(&opt);

  if (!opt.empty_pattern) {
    if (opt.active_flags[OPT_i]) {
      data.regflag = REG_EXTENDED | REG_ICASE;
    }
    for (int i = 0; i < opt.number_of_patterns; i++) {
      int err = regcomp(&reg[i], opt.list_of_patterns[i], data.regflag);
      regError(err, &reg[i]);
    }
  }

  for (int i = 0; i < opt.number_of_files; i++) {
    if ((fp = fopen(opt.list_of_files[i], "r")) == NULL) {
      if (!opt.active_flags[OPT_s]) {
        fprintf(stderr, "%s: ОШИБКА: Файла с таким именем несуществует!!!\n",
                opt.list_of_files[i]);
      }
      continue;
    }

    getFile(i, reg, fp, &opt, &data);

    fclose(fp);
  }

  if (!opt.empty_pattern) {
    for (int i = 0; i < opt.number_of_patterns; i++) {
      regfree(&reg[i]);
    }
  }
  optionsFree(&opt);
  dataFree(&data);

  return EXIT_SUCCESS;
}

//=========================================================================================

void firstErrorCheck(Options *opt) {
  if (opt->number_of_patterns == 0) {
    fprintf(stderr, "ОШИБКА: Отсутствует ШАБЛОН!!!\n");
    exit(EXIT_FAILURE);
  }

  if (opt->number_of_files == 0) {
    fprintf(stderr, "ОШИБКА: Отсутствует название файла!!!\n");
    exit(EXIT_FAILURE);
  }
}

void checkSomeFlags(Options *opt) {
  if (opt->active_flags[OPT_o] &&
      (opt->empty_pattern || opt->active_flags[OPT_v])) {
    exit(EXIT_SUCCESS);
  }
}

void regError(int err, const regex_t *reg) {
  if (err) {
    char buf_err[200];
    regerror(err, reg, buf_err, sizeof(buf_err));
    fprintf(stderr, "ОШИБКА: regcomp: %s\n", buf_err);
    exit(EXIT_FAILURE);
  }
}

void getFile(int i, regex_t *reg, FILE *fp, Options *opt, Data_grep *data) {
  char *buf = NULL;
  size_t buf_size = 50;

  data->number_of_line = 0;
  data->number_of_matched_lines = 0;

  while (getline(&buf, &buf_size, fp) != -1) {
    data->number_of_line++;

    if (opt->empty_pattern) {
      if (!opt->active_flags[OPT_v]) {
        putS(buf, opt->list_of_files[i], opt, data);
        data->number_of_matched_lines++;
      }
      continue;
    }

    int check_v = 0;
    for (int j = 0; j < opt->number_of_patterns; j++) {
      if (regexec(&reg[j], buf, 0, NULL, 0) == 0) {
        if (!opt->active_flags[OPT_v]) {
          data->number_of_matched_lines++;
          if (!opt->active_flags[OPT_o]) {
            putS(buf, opt->list_of_files[i], opt, data);
          } else {
            workO(buf, reg, j, opt, data, opt->list_of_files[i]);
          }
          break;
        }
      } else {
        check_v++;
        if (opt->active_flags[OPT_v] && check_v == opt->number_of_patterns) {
          data->number_of_matched_lines++;
          putS(buf, opt->list_of_files[i], opt, data);
        }
      }
    }
  }

  putS_cl(opt->list_of_files[i], opt, data);

  if (buf) {
    free(buf);
    buf = NULL;
  }
}

void putS(char *buf, char *filename, Options *opt, Data_grep *data) {
  if (!opt->active_flags[OPT_c] && !opt->active_flags[OPT_l]) {
    ifNAndNotH(opt, data, filename);

    fputs(buf, stdout);
  }
}
