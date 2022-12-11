#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *p = (unsigned char*)s;
    unsigned char *isCharFind = NULL;
    while ((s!= NULL) && (n--)) {
        if (*p != (unsigned char)c) {
            p++;
        } else {
            isCharFind = p;
            break;
        }
    }
    return isCharFind;
}
