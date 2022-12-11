#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
  int len = mx_strlen(str);
  int i = 0;
  int j = 0;
  char *tmp1 = mx_strnew(len);
  char *tmp2 = mx_strtrim(str);
  while (tmp2[i] != '\0') {
    if (!(mx_isspace(tmp2[i]) && mx_isspace(tmp2[i + 1]))) {
      tmp1[j] = tmp2[i];
      j++;
    }
    i++;
  }
  mx_strdel(&tmp2);
  return tmp1;
}
