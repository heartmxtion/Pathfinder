#include <libmx.h>

double mx_pow(double n, unsigned int pow){
	double d = 1.0;
	for(unsigned int i = 0; i < pow; i++){
		d = d * n;
	}
	return d;
}

