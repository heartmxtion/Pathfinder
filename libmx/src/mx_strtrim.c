#include <libmx.h>

char *mx_strtrim(const char *str) {
	if (str == NULL) {
		return NULL;
	}
	int first = 0;
	int last = mx_strlen(str);
	char *trim;
	for (int i = 0; i < mx_strlen(str); i++) {
		if (!mx_isspace(str[i])) {
			first = i;
			break;
		}
	}
	for (int i = mx_strlen(str); i >= first; i--) {
		if (!mx_isspace(str[i])) {
			last = i;
			break;
		}
	}
	trim = mx_strnew(last - first + 2);
	for (int i = first, j = 0; i <= last; i++) {
		trim[j] = str[i];
		j++;
	}
	return trim;
}

