#include <pathfinder.h>

void way_to_str(t_node **res_paths, char **path, int path_length){
	int i = 0;
	t_node **temp_res = res_paths;
	while(i < path_length){//Way to str
		char *paths_itoa = mx_itoa(res_paths[i]->all_paths);
		char *temp_str = mx_strdup(paths_itoa);
		temp_str = mx_strjoin(temp_str, "|");
		while(temp_res[i] != NULL){
			temp_str = mx_strjoin(temp_str, temp_res[i]->name);
			temp_str = mx_strjoin(temp_str, ",");
			temp_res[i] = temp_res[i]->parent;
		}
		path[i] = temp_str;
		i++;
	}
}

void reverce_way(char **path, int path_length){
	int i = 0;
	while(i < path_length){//Reverce way
		char *temp_str = NULL;
		char **temp_arr_one = mx_strsplit(path[i], '|');
		char **temp_arr_two = mx_strsplit(temp_arr_one[1], ',');
		int j = amount_of_el(temp_arr_two)-1;
		while(j >= 0){
			temp_str = mx_strjoin(temp_str, temp_arr_two[j]);
            		temp_str = mx_strjoin(temp_str, ",");
            		j--;
            	}
            	j = 0;
		temp_str = mx_strjoin( temp_str, "|");
		temp_str = mx_strjoin( temp_str, temp_arr_one[0]);
		path[i] = temp_str;
		i++;
	}
}

void path_to_str(t_node **res_paths, char **path, int path_length){
	way_to_str(res_paths, path, path_length);
	reverce_way(path, path_length);
}

