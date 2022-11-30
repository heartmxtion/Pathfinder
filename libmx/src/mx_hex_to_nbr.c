#include <libmx.h>

unsigned long mx_hex_to_nbr(const char *hex) {
	if (!hex) {
		return 0;
	}
	long i = 0, temp, value, res = 0, lenght = 0;
	while (hex[lenght] != '\0') {
		lenght++;
	}
	lenght--;
	while (hex[i] != '\0') {
		if (hex[i] >= '0' && hex[i] <= '9') {
		value = hex[i] - 48;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F') {
			value = hex[i] - 65 + 10;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f') {
			value = hex[i] - 97 + 10;
		}
		else {
			return 0;
		}
		temp = 1;
		for (long j = 0; j < lenght; j++) { 
			temp *= 16;
		}
		res += value * temp;
		lenght--;
		i++;
	}
	return res;
}

