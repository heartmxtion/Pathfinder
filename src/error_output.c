#include <pathfinder.h>

void error_out_usage(){
	mx_printerr("usage: ./pathfinder [filename]\n");
	exit(0);
}

void error_out_lengths(){
	mx_printerr("error: sum of bridges lengths is too big\n");
	exit(1);
}

void error_out_invalid_number(){
	mx_printerr("error: invalid number of islands\n");
	exit(1);
}

void error_out_first_line(){
	mx_printerr("error: line 1 is not valid\n");
	exit(1);
}

void error_out_find_line(int formula_to_find){
	mx_printerr("error: line ");
	mx_printerr(mx_itoa(formula_to_find));
	mx_printerr(" is not valid\n");
	exit(1);
}

void error_out_duplicate(){
	mx_printerr("error: duplicate bridges\n");
	exit(1);
}
