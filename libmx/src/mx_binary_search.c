#include <libmx.h>

int mx_binary_search(char **arr, int size, const char *s, int *count){
	(*count) = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] == NULL){
			return -1;
		}
		for(int j = 0; j < size - 1; j++){
			if(mx_strcmp (arr[j], arr[j + 1]) > 0){
				char *temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	int f = 0, l = size - 1, mid = (f + l)/2;
	while(f <= l){
		(*count)++;
		if(mx_strcmp(arr[mid], s) < 0){
			f = mid + 1;
		}
		else if(mx_strcmp (arr[mid], s) == 0){
			return mid;
		}
		else{
			l = mid - 1;
		}
		mid = (f + l)/2;
	}
	if (f > l){
		*count = 0;
		return -1;
	}
	return -1;
}

