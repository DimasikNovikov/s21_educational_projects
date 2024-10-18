#include "cat_options.h"

int displayFile(int, char **, struct Options *);

int main(int argc, char *argv[]) {
  int flag_filename = 0;

  struct Options opt;

  if (argc > 1) {
    opt = findOptions(argc, argv);

    flag_filename = displayFile(argc, argv, &opt);
  }

  if (flag_filename == 0) {
    printf("Отсутствует название файла!!!\n");
  }

  return 0;
}

int displayFile(int argc, char **argv, struct Options *opt) {
  FILE *file = NULL;
  int ch;
  int flag_filename = 0;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      flag_filename++;
      file = fopen(argv[i], "r");
      if (file == NULL) {
        printf("%s: Файла с таким именем не существует!!!\n", argv[i]);
        continue;
      }

      while ((ch = fgetc(file)) != EOF) {
        if (selectedOptions(&ch, opt)) {
          continue;
        }

        putchar(ch);
      }

      if (fclose(file) != 0) {
        printf("Ошибка закрытия файла!");
      }
    }
  }

  return flag_filename;
}
