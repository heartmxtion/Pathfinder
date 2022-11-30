#include <pathfinder.h>

t_node *new_node_gr(int all_paths, char *name) { //Create node
	t_node *new_node = (t_node*)malloc(sizeof(t_node));
	new_node->parent = NULL;
	new_node->name = mx_strdup(name);
	new_node->all_paths = all_paths;
	return new_node;
}

void push_node_gr(char *name, int all_paths, t_node* parent) { //Push node
	t_node* temp = new_node_gr(all_paths, name);
	temp->parent = parent;
	parent = temp;
	free(temp);
}

t_field *new_field(int **arr, char **points, int size) {
	t_field *new_fi = (t_field*)malloc(sizeof(t_field));
	new_fi->arr = arr;
	new_fi->points = points;
	new_fi->size = size;
	return new_fi;
}
