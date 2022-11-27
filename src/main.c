#include <pathfinder.h>

int main(int argc, char *argv[]){
	//usage
	check_argc(argc);
	
	//Convert file to str
	char *str_file = mx_file_to_str(argv[1]);

	//First number
	int f_int = first_num(str_file);

	//Split for a lines without first num
	char **str_without_first_num = mx_strsplit(&str_file[mx_get_char_index(str_file, '\n')+1], '\n');

	//Amount of lines
	int count_lines = amount_of_lines(str_without_first_num);
	
	//Split for a points
	char **points = (char **)malloc((count_lines*9)*2);
	unsigned long sum_edge = split_for_points(str_without_first_num, points);
	
	//Check for extra new line in file
	check_extra(str_file);
	
	//Delete dublicate and check for correct points
	points = dup_remove(count_lines, points, f_int);

	//Create and fill matrix by -1
	int **arr = (int **)malloc((f_int*f_int)*sizeof(int));
	fill_arr_by_fint(f_int, arr);
	
	//Create field by structure(needs to divide num of elements in functions cuz auditor)
	t_field *field = new_field(arr, points, f_int);

	//Fill matrix and check for dublicats
	fill_arr_and_check_dub(str_without_first_num, field);

	//Check for too long distance
	too_big_lengths(sum_edge);
	
	//Only for know right memory
	int path_lenght = memory_filter(field);

	//Create result paths graph and fill by NULL
	t_node **res_paths = (t_node **) malloc((path_lenght + 1) * sizeof(t_node *));
	res_path(path_lenght, res_paths);

	//Doing algorithm
	path_lenght = main_algorhitm(path_lenght, res_paths, field);

	//Convert path from graph to str
	char **path = (char **)malloc((path_lenght*path_lenght)*sizeof(char));
	path_to_str(res_paths, path, path_lenght);

	//Sort and output the path
	sort_and_out_path(path, path_lenght, field);
}

