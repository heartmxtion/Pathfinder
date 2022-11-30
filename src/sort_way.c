#include <pathfinder.h>

void sort_by_distance(char **path, unsigned long size){
	unsigned long i = 0;
	while(i < size){
		unsigned long j = 0;
		while(j < size-1){
			char **temp1 = mx_strsplit(path[j], '|');
			char **temp2 = mx_strsplit(path[j+1], '|');
			if(mx_atoi(temp1[1]) > mx_atoi(temp2[1])){
				char *temp_path = mx_strdup(path[j]);
				path[j] = mx_strdup(path[j+1]);
				path[j+1] = mx_strdup(temp_path);
			}
			j++;
		}
		i++;
	}

}

int only_min_paths(char **temp_num, char **only_min, char **path, unsigned long size){
	int size_min = 0;
	unsigned long i = 0;
	while(i < size){
		char** temp = mx_strsplit(path[i], '|');
		if(mx_atoi(temp_num[1]) != mx_atoi(temp[1])){
			break;
		}
		only_min[size_min] = mx_strdup(path[i]);
		size_min++;
		i++;
	}
	return size_min;
}

void sort_path_names(char **path, t_field *field, unsigned long size){
	unsigned long i = 0;
	while(i < size){
		unsigned long j = 0;
		while(j < size-1){
			char **temp_without_num1 = mx_strsplit(path[j], '|');
			char **temp_without_num2 = mx_strsplit(path[j+1], '|');
			char **temp1 = mx_strsplit(temp_without_num1[0], ',');
			char **temp2 = mx_strsplit(temp_without_num2[0], ',');
			int z = 1;
			while(true){
				if(!temp1[z] || !temp2[z]){
					break;
				}
				if(get_ind_strarr(field->points, temp1[z]) > get_ind_strarr(field->points, temp2[z]) 
									&& mx_strcmp(temp1[z-1], temp2[z-1]) == 0) {
					char *temp_path = mx_strdup(path[j]);
					char *temp_path_two = mx_strdup(path[j+1]);
					char *temp_path_three = mx_strdup(temp_path);
					path[j] = temp_path_two;
					path[j+1] = temp_path_three;
					break;
				}
				z++;
			}
			j++;
		}
		i++;
	}
}

int amount_of_el(char **arr) {
	int res = 0;
	while(arr[res]){
		res++;
	}
	return res;
}

void sort_path_all_out(char **only_min, t_field *field, int size_min){
	int i = 0;
	while(i < size_min){
		char **temp = mx_strsplit(only_min[i], '|');
		path_out(temp[0], field);
		i++;
	}
}

void sort_path_all(t_field *field, char **path, unsigned long size){
	//Sort by distance
	sort_by_distance(path, size);
	//Write only min paths
	char **temp_num = malloc((size*8)*sizeof *temp_num);
	temp_num = mx_strsplit(path[0], '|');
	char **only_min = (char **)malloc((size*size*2)*sizeof(char));
	int size_min = only_min_paths(temp_num, only_min, path, size);
	//Sort by names
	sort_path_names(only_min, field, size_min);
	//Output
	sort_path_all_out(only_min, field, size_min);
	//Clean mem
	free(temp_num);
	free(only_min);
}

