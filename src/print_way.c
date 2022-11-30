#include <pathfinder.h>

void border_print(){
	for(int i = 0; i < 40; i++){
		mx_printstr("=");
	}
	mx_printchar('\n');
}

void path_print(char *path){
	char **temp = mx_strsplit(path, ',');
	int temp_size = amount_of_el(temp);
	border_print();
	mx_printstr("Path: ");
	mx_printstr(temp[0]);
	mx_printstr(" -> ");
	mx_printstr(temp[temp_size-1]);
	mx_printchar('\n');
	free(temp);
}

void route_print(char *path){
	char **temp = mx_strsplit(path, ',');
	int temp_size = amount_of_el(temp);
	mx_printstr("Route: ");
	for (int i = 0; i < temp_size; i++){
		mx_printstr(temp[i]);
		if(i < temp_size-1 && i >= 0){
			mx_printstr(" -> ");
		}
	}
	free(temp);
}

void distance_print(char *path, t_field *field){
	char **temp = mx_strsplit(path, ',');
	int temp_size = amount_of_el(temp);
	int first = get_ind_strarr(field->points, temp[0]);
	int second = get_ind_strarr(field->points, temp[1]);
	int sum = 0;
	if(temp_size != 2){
		mx_printstr("\nDistance: ");
		mx_printint(field->arr[first][second]);
		sum = sum + field->arr[first][second];
		int i = 0;
		while(i < temp_size-2){
			first = get_ind_strarr(field->points, temp[i+1]);
			second = get_ind_strarr(field->points, temp[i+2]);
			mx_printstr(" + ");
			sum = sum + field->arr[first][second];
			mx_printint(field->arr[first][second]);
			i++;
		}
		mx_printstr(" = ");
		mx_printint(sum);
		mx_printchar('\n');
		border_print();
	} else {
		mx_printstr("\nDistance: ");
		mx_printint(field->arr[first][second]);
		mx_printchar('\n');
		border_print();
	}
	free(temp);
}
void path_out(char *path, t_field *field) {
	//Path
	path_print(path);
	//Route
	route_print(path);
	//Distance
	distance_print(path, field);
	
}

