#include <pathfinder.h>

int is_full(t_queue** queue) { //Queue is full
	if((*queue) == NULL){
		return -1;
	}
	return 1;
}

t_queue* new_node_qu(t_node *node) {
	t_queue* new_node = (t_queue*)malloc(sizeof(t_queue));
	new_node->priority = node->all_paths;
	new_node->node = node;
	new_node->next = NULL;
	return new_node;
}

void push_to_qu(t_queue** head, t_node *node) { //Enter the element for priority
	t_queue* start = (*head);
	t_queue* temp_node = new_node_qu(node);
	if((*head) == NULL) {
		(*head) = temp_node;
		return;
	}
	if(node->all_paths < (*head)->priority) {
		temp_node->next = *head;
		(*head) = temp_node;
	} else {
		while(start->next != NULL && node->all_paths > start->next->priority){
			start = start->next;
		}
		temp_node->next = start->next;
		start->next = temp_node;
	}
}

void pop_front(t_queue** head) {//Delete first element
	t_queue* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

