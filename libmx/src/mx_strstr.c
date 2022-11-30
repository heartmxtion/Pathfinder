#include <libmx.h>

char *mx_strstr(const char *haystack, const char *needle) {
	int length1 = mx_strlen(haystack);
	int length2 = mx_strlen(needle);
	for (int i = 0; i < length1; haystack++, i++) {
		char *temp = mx_strchr(haystack, haystack[0]);
		if (mx_strncmp(temp, needle, length2) == 0) {
			return (char*)haystack;
		}
	}
	return NULL;
}

