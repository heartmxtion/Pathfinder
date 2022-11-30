#include <libmx.h>

int mx_get_substr_index(const char *str, const char *sub) {
	int i = 0, sub_length = 0;
	if (sub && str) {
		sub_length = mx_strlen(sub);
		while (*str) {
			if (mx_strncmp(str++, sub, sub_length) == 0) {
				return i;
			}
			i++;
		}
		return -1;
	}
	return -2;
}

