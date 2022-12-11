#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;
    int count = mx_strlen(str);

    while(mx_isspace(str[count - 1])) count--;
    while(*str && mx_isspace(*str)) str++, count--;

    return mx_strndup(str, count);
}
