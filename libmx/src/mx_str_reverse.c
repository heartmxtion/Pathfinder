#include <libmx.h>

void mx_str_reverse(char *s) {
	int lenght;
	lenght = mx_strlen(s);
	for(int i = 0; i < lenght/2; i++) {
		mx_swap_char(&s[i], &s[lenght-1-i]);
	}
}

