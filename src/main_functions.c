#include <pathfinder.h>

int first_num(char *str_file){
	if(str_file[0] == '\n'){
		error_out_first_line();
	}
	char *f_char = mx_strndup(str_file, mx_get_char_index(str_file, '\n'));
	return check_edge(f_char); 
}

int amount_of_lines(char **str_without_first_num){
	int count_lines = 0;
	for(; str_without_first_num[count_lines] != NULL; count_lines++);
	return count_lines;
}

int split_for_points(char **routes, char **points){ //Split for a points + sum edges
	int counter = 0, i = 0;
	unsigned long sum_edge = 0;
	while(routes[i]) {
		int char_index_one = mx_get_char_index(routes[i], '-');
		int char_index_two = mx_get_char_index(routes[i], ',');
		char *f_point = mx_strndup(routes[i], char_index_one);
		char *dup_f_point = mx_strdup(f_point);
		points[counter] = dup_f_point;
		counter++;
		int len_f_point = mx_strlen(f_point);
		char *s_point = mx_strndup(&routes[i][char_index_one + 1], char_index_two - len_f_point - 1);
		char *dup_s_point = mx_strdup(s_point);
		points[counter] = dup_s_point;
		counter++;
		char *edges = mx_strdup(&routes[i][char_index_two + 1]);
		if(check_line(f_point, s_point, edges) > 0) {
			error_out_find_line(i+2);
		}
		sum_edge = sum_edge + mx_atoi(edges);
		i++;
	}
	return sum_edge;
}

void fill_arr_by_fint(int f_int, int **arr){ //fill matrix by -1
	for(int i = 0; i < f_int; i++){
		arr[i] = (int*)malloc((f_int) * sizeof(int));
	}
	for(int i = 0; i < f_int; i++){
		for(int j = 0; j < f_int; j++){
			arr[i][j] = -1;
		}
	}
}

void fill_arr_and_check_dub(char **routes, t_field *field){
	for(int i = 0; routes[i]; i++) {
		int char_index_one = mx_get_char_index(routes[i], '-');
		int char_index_two = mx_get_char_index(routes[i], ',');
		char *f_point = mx_strndup(routes[i], char_index_one);
		int len_f_point = mx_strlen(f_point);
		char *s_point = mx_strndup(&routes[i][char_index_one + 1], char_index_two - len_f_point - 1);
		char *edge_num = mx_strdup(&routes[i][char_index_two + 1]);
		int f_ind = get_ind_strarr(field->points, f_point);
		int s_ind = get_ind_strarr(field->points, s_point);//000000
		if(field->arr[f_ind][s_ind] == -1 && field->arr[s_ind][f_ind] == -1){
			field->arr[f_ind][s_ind] = mx_atoi(edge_num);
			field->arr[s_ind][f_ind] = mx_atoi(edge_num);
		} else {
			error_out_duplicate();
		}
	}
}

int memory_filter(t_field *field){
	int path_lenght = 0;
	for(int points_i = 0; points_i < field->size; points_i++) {
		for(int points_j = points_i; points_j < field->size; points_j++) {
			if(points_i != points_j) {
				t_node **a = pathfinder(field, points_i, points_j);
				for(int j = 0; a[j] != NULL; j++) {
					path_lenght++;
				}
			}
		}
	}
	return path_lenght;
}

void res_path(int path_lenght, t_node **res_paths){
	int j = 0;
	while (j < path_lenght){
		res_paths[j] = NULL;
		j++;
	}
	j = 0;
}

int main_algorhitm(int path_lenght, t_node **res_paths, t_field *field){
	path_lenght = 0;
	for(int points_i = 0; points_i < field->size; points_i++) {
		for(int points_j = points_i; points_j < field->size; points_j++) {
			if(points_i != points_j) {
				t_node **a = pathfinder(field, points_i, points_j);
				int j = 0;
				while(a[j] != NULL) {
					res_paths[path_lenght] = (t_node*)malloc(sizeof(t_node));
					res_paths[path_lenght] = a[j];
					path_lenght++;
					j++;
				}
			}
		}
	}
	return path_lenght;
}

void sort_and_out_path(char **path, int path_lenght, t_field *field){
	int length_one_path = 0;
	char **res = (char **)malloc((2147483647/100)*sizeof(char));
	for(int i = 0; i < field->size; i++){
		for(int j = i; j < field->size; j++){
			int k = 0;
			while(k < path_lenght){
				char **tmp_without_num = mx_strsplit(path[k], '|');
				char **tmp = mx_strsplit(tmp_without_num[0], ',');
				int comp_str_one = mx_strcmp(tmp[0], field->points[i]);
				int count_elems = amount_of_el(tmp);
				int comp_str_two = mx_strcmp(tmp[count_elems-1], field->points[j]);
				if(comp_str_one == 0 && comp_str_two == 0){
					char *path_dup = mx_strdup(path[k]);
					res[length_one_path] = path_dup;
					length_one_path++;
				}
				k++;
			}
			if(length_one_path != 0){
				sort_path_all(field, res, (unsigned long)length_one_path);
			}
			length_one_path = 0;
		}
	}
}

