#include <libmx.h>

char *mx_strcat(char *restrict s1, const char *restrict s2) {
	int s1_length = mx_strlen(s1), s2_length = mx_strlen(s2);
	int i = s1_length, j = 0;
	while (i < (s1_length + s2_length)){
		s1[i++] = s2[j++];
	}
	s1[i++] = '\0';
	return s1;
}

