#include <libmx.h>

bool mx_isspace(char c){
	if((c >= 0x09 && c <= 0x0D) || (c == 0x20)) {
		return true;
	}
	return false;
}

