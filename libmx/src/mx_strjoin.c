#include <libmx.h>

char *mx_strjoin(char const *s1, char const *s2) {
	if (s1 == NULL && s2 == NULL) {
		return NULL;
	}
	else if (s1 == NULL) {
		return mx_strdup(s2);
	}
	else if (s2 == NULL) {
		return mx_strdup(s1);
	}
	else {
		char *str_res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
		str_res =  mx_strcpy(str_res, s1);
		str_res =  mx_strcat(str_res, s2);
		return str_res;
	}
}

