#include <libmx.h>

char *mx_nbr_to_hex(unsigned long nbr){
	if (nbr < 1){
		return 0;
	}
	unsigned long size = 0;
	unsigned long nbr_copy = nbr;
	while(nbr_copy){
		unsigned long r = (nbr_copy % 16);
		if(r > 9){
			r += (unsigned long)'a' - 10;
		}
		else{
			r+=(unsigned long)'0';
		}
		size++;
		nbr_copy /= 16;
	}
	if (size < 0) {
		return NULL;
	}
	char *tmp = mx_strnew(size);
	while(nbr){
		unsigned long r = (nbr % 16);
		if(r > 9){
			r += (unsigned long)'a' - 10;
		}
		else{
			r+=(unsigned long)'0';
		}
		tmp[--size] = (char)r;
		nbr /= 16;
	}
	return tmp;
}

