#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *prev;
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void double_link_list_add_to_head(int data){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	if(head == NULL){//Liste boþsa
	new_node->data = data;
	new_node->next = NULL;
	head = tail = new_node;
	new_node->prev = NULL;
	}
	else{
		new_node->data = data;
		tail = NULL;
		new_node->next = head;
		head = new_node;
	}
}

void double_link_list_add_anywhere(int x,int data){
struct node *new_node = (struct node*)malloc(sizeof(struct node));
new_node->data = data;

if(x == 1){
	double_link_list_add_to_head(data);
	return;
}

struct node *ptr = head;
for(int i = 1;( (i < x - 1 )  && (ptr != NULL) );i++){
	ptr = ptr->next;
}
if(ptr == NULL || ptr->next == NULL){
	printf("Gecersiz Konum:\n");
	return;
}
new_node->next = ptr->next;
new_node->prev = ptr;
ptr->next->prev = new_node;
ptr->next = new_node;

}

void print(){
	struct node *temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

void delete_head(){
	if(head == NULL) return;
	
	struct node *temp = head;
	head = head->next;
	if(head != NULL){
		head->prev = NULL;
	}
	free(temp);
}

void delete_tail(){
	if (head == NULL) return;
	
	struct node *temp = head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

void delete_position(int position){
if(head == NULL) return;

struct node *temp = head;

for(int i = 1; i < position && temp != NULL;i++){
	temp = temp->next;
}

if(temp == NULL){
	printf("Gecersiz Konum.\n");
	return;
}

if(temp->prev != NULL){
	temp->prev->next = temp->next;
}else{
	head = temp->next;
}

if(temp->next != NULL){
	temp->next->prev = temp->prev;
}

free(temp);
}



int main(){
	double_link_list_add_to_head(1);
	double_link_list_add_to_head(2);
	double_link_list_add_to_head(3);
	double_link_list_add_to_head(4);
	 double_link_list_add_anywhere(2,5);
	 delete_position(3);
	print();
}
		
		
