#include <libmx.h>

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	if (!str || !sub || !replace || (mx_strlen(str) <= mx_strlen(sub))) {
		return NULL;
	} 
	int sum = mx_strlen(replace) - mx_strlen(sub);
	int length = mx_strlen(str) + mx_count_substr(str, sub) * sum;
	char *mem = mx_strnew(length);
	bool b = false;
	for (int i = 0; i < length; i++, str++) {
		b = false;
		if (!mx_strncmp((char *)str, (char *)sub, mx_strlen(sub))) {
			str += mx_strlen(sub);
			for (int j = 0; j < mx_strlen(replace); i++, j++) {
				mem[i] = replace[j];
			}
			b = true;
		}
		mem[i] = *str;
		if (b) {
			str--;
			i--;
		}
	}
	return mem;
}

