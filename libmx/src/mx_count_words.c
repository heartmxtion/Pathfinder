#include <libmx.h>

int mx_count_words(const char *str, char c) {
	if (str == NULL) {
		return -1;
	}
	bool b = true;
	unsigned i = 0;
	while (*str) {
		if (*str == c) {
			b = true;
		}
		else if (b) {
			b = false;
			i++;
		}
		str++;
	}
	return i;
}

