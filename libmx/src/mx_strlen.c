#include <libmx.h>

int mx_strlen(const char *s) {
	int lenght = 0;
	while (*s){
	s++;
	lenght++;
	}
	return lenght;
}

