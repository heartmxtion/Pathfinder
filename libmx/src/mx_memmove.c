#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	unsigned char *temp = (unsigned char*)malloc(len * sizeof(unsigned char));
	temp = mx_memcpy(temp, src, len);
	dst = mx_memcpy(dst, temp, len);
	free(temp);
	temp = NULL;
	return dst;
}

