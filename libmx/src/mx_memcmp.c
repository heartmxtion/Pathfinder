#include <libmx.h>

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	if (n == 0) {
		return 0;
	}
	const unsigned char *s1_temp = s1;
	const unsigned char *s2_temp = s2;
	size_t i = 0;
	while ((*s1_temp == *s2_temp) && (i != n)) {
		if (*s2_temp == '\0') {
			return 0;
		}
		i++;
		s1_temp++;
		s2_temp++;
	}
	return *s1_temp - *s2_temp;
}

