#include <libmx.h>

char *mx_strndup(const char *s1, size_t n) {
	char *dup = NULL;
	size_t length = (size_t)mx_strlen(s1);
	if (n < length) {
		length = n;
	}
	dup = mx_strnew(length);
	mx_strncpy(dup, s1, length);
	return dup;
}

