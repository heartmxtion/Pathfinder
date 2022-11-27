#include <libmx.h>

char **mx_strsplit(const char *s, char c) {
	if (!s) {
		return NULL;
	}
	char **arr = NULL;
	int i = 0, length = 0;
	arr = (char**)malloc((mx_count_words(s, c) + 1) * sizeof(char*));
	while ((*s) && (*s != '\0')) {
		length = 0;
		if (*s != c) {
			const char *temp = s;
			while (temp[length] && temp[length] != c) {
				length++;
			}
			arr[i] = mx_strndup(s, length);
			s += length;
			i++;
			continue;
		}
	s++;
	}
	arr[i] = NULL;
	return arr;
}

