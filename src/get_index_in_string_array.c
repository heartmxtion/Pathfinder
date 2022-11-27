#include <pathfinder.h>

int get_ind_strarr(char **arr, char *sub){
	int i = 0;
	while(arr[i]){
		if(mx_strcmp(arr[i], sub) == 0){
			return i;
		}
		i++;
	}
	i = 0;
	return -1;
}

