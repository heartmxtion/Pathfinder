#include <libmx.h>

void *mx_realloc(void *ptr, size_t size) {
	size_t cur_size;
	void *new_ptr;
	if (!ptr) {
		return malloc(size);
	}
	cur_size = malloc_size(ptr); //Ubuntu malloc_usable_size(ptr)
	if (size <= cur_size) {
		return ptr;
	}
	new_ptr = malloc(size);
	mx_memcpy(new_ptr, ptr, cur_size);
	free(ptr);
	return new_ptr;
}

