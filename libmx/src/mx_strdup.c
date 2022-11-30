#include <libmx.h>

char *mx_strdup(const char *str) {
	const char *temp = str; 
	int size = 0;
	while (*temp++) {
		size++;
	}
	if (size < 0) {
		return NULL;
	}
	char *dst = (char *)malloc((size + 1) * sizeof(char));
	for (int i = 0; i <= size; i++) {
		dst[i] = '\0';
	}
	char *ptr = dst;
	int i = 0;
	while ((dst[i] = str[i]) != '\0') {
		i++;
	}
	return ptr;
}

