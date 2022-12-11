#include "../inc/libmx.h"

char *mx_strndup(const char* s1, size_t n) {
	char *copy;
	size_t len;

	len = mx_strnlen(s1, n);
	copy = mx_strnew(len + 1);
	if (copy != NULL) {
		mx_strncpy(copy, s1, len);
	}

	return copy;
}
