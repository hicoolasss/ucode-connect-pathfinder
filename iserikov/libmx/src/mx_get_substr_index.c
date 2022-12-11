#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -2;

    char *dest = mx_strstr(str, sub);

    if (dest == NULL) return -1;

    return (char*)dest - str;
}
