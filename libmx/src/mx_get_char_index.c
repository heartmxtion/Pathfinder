#include <libmx.h>

int mx_get_char_index(const char *str, char c) {
	if (!str || !*str) {
		return -2;
	}
	int i = 0, length = mx_strlen(str);
	while (*str) {
		if (*str == c) {
			break;
		}
	i++;
	str++;
	}
	if (i >= length) {
		return -1;
	}
	return i;
}

