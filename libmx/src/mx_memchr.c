#include <libmx.h>

void *mx_memchr(const void *s, int c, size_t n) {
	unsigned char *s_temp = (unsigned char *)s;
	while (n--) {
		if (*s_temp == (unsigned char)c) {
			return s_temp;
		}
		s_temp++;
	}
	return NULL;
}

