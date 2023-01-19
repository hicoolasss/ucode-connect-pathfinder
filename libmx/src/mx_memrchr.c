#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *p = (const unsigned char *)s + n - 1;

	while (n--) {
		if (*p == (unsigned char)c)
			return (void *)p;
		p--;
	}

	return NULL;
}
