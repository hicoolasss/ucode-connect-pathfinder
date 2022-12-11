#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    char *src;
    char *p;
    int len = 0;
    while (str[len])
        len++;
    src = malloc(len + 1);
    p = src;
    while (*str)
        *p++ = *str++;
    *p = '\0';
    return src;
}
