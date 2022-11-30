#include <pathfinder.h>

void check_argc(int argc){
	if(argc != 2){
		error_out_usage();
	}
}

int check_edge(const char *num){
	if(mx_strcmp(num, "") == 0){
		error_out_first_line();
	}
	for(int i = 0; i < mx_strlen(num); i++){
		if(!mx_isdigit(num[i])){
			return -1;
		}
	}
	if (mx_atoi(num) < 0) {
		error_out_first_line();
	}
	if(mx_atoi(num) <= 2147483647){
		return mx_atoi(num);
	}
	error_out_first_line();
	return -1;
}

int check_name_of_point(const char *word) {
	int i = 0;
	while(i < mx_strlen(word)) {
		if(!mx_isalpha(word[i])){
			return 1;
		}
		i++;
	}
	return -1;
}

int check_line(const char *f_point, const char *s_point, const char *edge) {
	if(!f_point || !s_point || !edge){
		return 1;
	}

	if(check_name_of_point(f_point) > 0 || check_name_of_point(s_point) > 0){
		return 1;
	}
	if(check_edge(edge) <= 0){
		return 1;
	}

	if(mx_strcmp(f_point, s_point) == 0){
		return 1;
	}
	return -1;
}

char **dup_remove(int count_lines, char **points, int f_int){//Delete dublicate in islands
	char **result = malloc((f_int*10)*sizeof *result);
	int i = 0, a = 1;
	result[0] = points[0];
	while(i < (count_lines*2)){
		if(get_ind_strarr(result, points[i]) == -1) {
			result[a] = points[i];
			a++;
		}
		if(a > f_int){
			error_out_invalid_number();
		}
		i++;
	}
	if(a < f_int) {
		error_out_invalid_number();
	}
	result[a] = points[(count_lines*2)-1];
	return result;
}

void check_extra(char *str_file){
	int extra_counter = 0;
	for(int i = 0; i < mx_strlen(str_file)-1; i++) {
		if(str_file[i] == '\n'){
			extra_counter++;
		}
		if(str_file[i] == '\n' && !mx_isalpha(str_file[i+1])) {
			error_out_find_line(extra_counter+1);
		}
	}
}

void too_big_lengths(unsigned long sum_lengths){
	if(sum_lengths > 2147483647){ //2147483647 - MAX INT
		error_out_lengths();
	}
}
