#include "../inc/libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
	const char *a, *b;
	b = s2;

	if (*b == 0) return (char *)s1;

	for(; *s1 != 0; s1 += 1) {
		if (*s1 != *b)
			continue;
		a = s1;

		while(1) {
			if (*b == 0)
				return (char*)s1;
			if (*a++ != *b++)
				break;
		}

		b = s2;
	}

	return NULL;
}
