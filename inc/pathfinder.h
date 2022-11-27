#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <libmx.h>

//////Graph
typedef struct s_node {
	int all_paths;
	char *name;
	struct s_node *parent; 
  
} t_node;

t_node *new_node_gr(int all_paths, char *name);
void push_node_qr(char *name, int all_paths, t_node* parent);
//////Graph

///////Queue with priority FIFO
typedef struct s_queue {
	int priority; 
	t_node *node;
	struct s_queue *next; 

} t_queue;

t_queue* new_node_qu(t_node *node);
///////Queue with priority FIFO

///////Field
typedef struct s_field {
	int **arr;
	char **points;
	int size;
} t_field;

t_field *new_field(int **arr, char **points, int size);
///////Field

int is_full(t_queue** queue);
void push_to_qu(t_queue** head, t_node *node);
void pop_front(t_queue** head);
///////Queue with priority

/////Algorithm
t_node **generate_heirs(t_field *field, t_node *parent);
t_node **pathfinder(t_field *field, int cur_x, int goal_x);
/////Algorithm

/////Sort
void sort_path_all(t_field *field, char **path, unsigned long size);
void sort_path_names(char **path, t_field *field, unsigned long size);
int amount_of_num(int num);
int amount_of_el(char **arr);
/////Sort

////Checks
void check_argc(int argc);
void check_extra(char *str_file);
int check_edge(const char *num);
int check_name_of_point(const char *word);
int check_line(const char *f_point, const char *s_point, const char *edge);
void too_big_lengths(unsigned long sum_lengths);
////Checks

//Error outputs
void error_out_usage();
void error_out_lengths();
void error_out_invalid_number();
void error_out_first_line();
void error_out_find_line(int formula_to_find);
void error_out_duplicate();
//Error outputs

//Main Functions
int first_num(char *str_file);
int amount_of_lines(char **str_without_first_num);
int split_for_points(char **str_without_first_num, char **points);
void fill_arr_by_fint(int f_int, int **arr);
void fill_arr_and_check_dub(char **str_without_first_num, t_field *field);
int memory_filter(t_field *field);
void res_path(int size_path, t_node **res_paths);
int main_algorhitm(int size_path, t_node **res_paths, t_field *field);
void sort_and_out_path(char **path, int size_path, t_field *field);
//Main Functions

int get_ind_strarr(char **arr, char *sub);

char **dup_remove(int count_lines, char **points, int f_int);

void path_out(char *path, t_field *field);

void path_to_str(t_node **res_paths, char **path, int size_path);
#endif
