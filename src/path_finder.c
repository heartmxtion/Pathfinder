#include <pathfinder.h>

void gen_arr(int size, t_node **type){
	int i = 0;
	while(i < size) { // add memory and fill array of some type with NULLs unitl i < size
		type[i] = (t_node*)malloc(sizeof(t_node));
		type[i] = NULL;
		i++;
	}
}

t_node **generate_heirs(t_field *field, t_node* parent) {
	int ind = 0;
	while(mx_strcmp(field->points[ind], parent->name) != 0){
		ind++;
	}

	t_node **heirs = (t_node **) malloc((field->size) * sizeof(t_node *));
	gen_arr(field->size, heirs);
	int i = 0;
	while(i < field->size) {
		if(i != ind && field->arr[ind][i] != -1 && parent != NULL) {
			t_node *temp = parent;
			int was = 0;
			int j = 0;
			while(temp != NULL) {
				if(mx_strcmp(temp->name, field->points[i]) == 0 || j > field->size) {
					was = 1;
					break;
				}
				temp = temp->parent;
				j++;
			}
			if(j > field->size){
				break;
			}
			if (was == 0) {
				heirs[i] = new_node_gr(parent->all_paths + field->arr[ind][i], field->points[i]);
			}
		}
		i++;
	}
	i = 0;
	int lenght = 0;
	while(i < field->size) {
		if(heirs[i] != NULL) { // count lenght of heirs
			lenght++;
		}
		i++;
	}

	t_node **heirs_res = (t_node **) malloc((lenght + 1) * sizeof(t_node *));
	i = 0;
	while(i < lenght + 1){
		heirs_res[i] = NULL;// fill heirs with NULLs
		i++;
	}

	lenght = 0;
	i = 0;
	while(i < field->size) {// If element is not NULL add a memory and add this element to result array of heirs
		if(heirs[i] != NULL) {
			heirs_res[lenght] = (t_node *) malloc(sizeof(t_node ));
			heirs_res[lenght] = heirs[i];
			lenght++;
		}
		i++;
	}
	i = 0;
	return heirs_res;
}
int sub_func(t_queue *order_value, int cheaker, t_node **heirs, int k){
	while(order_value != NULL) {
		if(mx_strcmp(order_value->node->name, heirs[k]->name) == 0) {
			if(order_value->node->all_paths < heirs[k]->all_paths) {
				cheaker = 0;
				break;
			}
		}
		order_value = order_value->next;
	}
	return cheaker;
}

t_node **pathfinder(t_field* field, int cur_x, int goal_x) {
	t_node *path = new_node_gr(0, field->points[cur_x]);
	t_queue *queue = new_node_qu(path);
	t_queue *queue_close = new_node_qu(path);

	t_node **paths = (t_node **)malloc(mx_pow(field->size, 2) * sizeof(t_node *));
	gen_arr(field->size, paths);
	int paths_ind = 0;
	int check = 0;

	while(is_full(&queue) > 0) {  // if queue is full then path = queue from node after pop the queue
		check++;
		path = queue->node;
		pop_front(&queue);

		t_node *temp = path;
		int j = 0;
		while(temp->parent != NULL) {
			if(j > field->size){
				break;
			}
			temp = temp->parent;
			j++;
		}
		if(j >= field->size){
			continue;
		}

		int not_in_points = 1;
		for(int h = 0; h < field->size; h++) {
			if(mx_strcmp(path->name, field->points[h]) == 0) {
				not_in_points = 0;
			}
		}
		if(not_in_points == 1){
			continue;
		}

		t_node **heirs = generate_heirs(field, path);
		int i = 0;
		while(heirs[i] != NULL){
			heirs[i]->parent = path;
			i++;
		}
		i = 0;
		while(heirs[i] != NULL) {
			if(mx_strcmp(heirs[i]->name, field->points[goal_x]) == 0) {
				paths[paths_ind] = heirs[i];
				paths_ind++;
			}

			t_queue *temp_queue = queue;
			int not_in_queue = 1;
			not_in_queue = sub_func(temp_queue, not_in_queue, heirs, i);

			int not_in_close_queue = 1;
			t_queue *queue_close_temp = queue_close;
			not_in_close_queue = sub_func(queue_close_temp, not_in_queue, heirs, i);

			if(not_in_queue > 0 && not_in_close_queue > 0) {
				push_to_qu(&queue, heirs[i]);
				push_to_qu(&queue_close, heirs[i]);
			}
			i++;
		}
	}
	return paths;
}

