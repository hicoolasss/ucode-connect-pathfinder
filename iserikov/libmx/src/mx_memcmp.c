#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    size_t i;
    const unsigned char *cs = (const unsigned char *)s1;
    const unsigned char *ct = (const unsigned char *)s2;

    for (i = 0; i < n; i++, cs++, ct++) {
        if (*cs < *ct)
            return -1;
        else if (*cs > *ct)
            return 1;
    }
    return 0;
}
