#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void add_head(int data){
	
struct node *new_node = (struct node*)malloc(sizeof(struct node));
		
	if(head == NULL){
		new_node->data = data;
		new_node->next = NULL;
		head = tail = new_node;
	}
	else{
	new_node->data = data;
	new_node->next = head;
	
	head = new_node;	
}
}

void add_tail(int data){

struct node *tmp = (struct node*)malloc(sizeof(struct node));

	if(head == NULL){
		tmp->data = data;
		tmp->next = NULL;
		head = tail = tmp;
	}
	else{
	
	tmp->data = data;
	
	
	tmp->next = NULL;
	
	tail->next = tmp;

	tail = tmp;	
}
}

int delete_(int data){

    struct node *prev = NULL;
    struct node *index = head;

    if(head==NULL){
        printf("Linked List is empty \n");
        return 1;
    }

    if(head->data==data){
        struct node *t = head;
        head = head->next;
        free(t);
        return 1;
    }

    while(index!=NULL && index->data!=data){
        prev = index;
        index = index->next;
    }

    if(index==NULL){
        printf("Data not found. \n");
        return 1;
    }

    prev->next = index->next;

    if(tail->data==data){
        tail = prev;
    }

    free(index);

    return 1;
}





void print(){
	struct node *tmp = head;
	while(tmp != NULL){
		printf(" %d", tmp->data);
		tmp = tmp->next;
	}
}

int main(){
	add_head(1);
	add_head(2);
	add_head(3);
	add_tail(4);
	add_tail(5);
	delete_(3);
	print();
	return 0;
}


