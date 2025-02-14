#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *root = NULL;

void add_to_head(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    
    if(head == NULL){
    	head = new_node;
    	new_node->next = root;
	}else{
		struct node *tmp = root;
		while(tmp->next != root){
			tmp = tmp->next;
		}
		new_node->next = root;
		tmp->next = new_node;
		root = new_node;
	}
	
}
