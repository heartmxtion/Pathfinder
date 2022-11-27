#include <libmx.h>

void mx_del_strarr(char ***arr) {
	if (!arr || !*arr || !**arr) {
		return;
	}
	int i = 0;
	while ((*arr)[i] != NULL) {
		mx_strdel(&(*arr)[i++]);
	}
	free(*arr);
	*arr = NULL;
}

