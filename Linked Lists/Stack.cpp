#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *top = NULL;

int push(int data)
{
	//stack is empty
	if(top == NULL){
		struct node *link = (struct node*)malloc(sizeof(struct node));
		link->data = data;
		link->next = NULL;	
		
		top = link;
			
		}
		//stack's not empty
		else{
			struct node *point = (struct node*)malloc(sizeof(struct node));
			point->data = data;
			point->next = top;
			
			top = point;
		}
			
	return 1;
}

int pop(){
	if(top == NULL){
		printf("Stack is empty.\n");
		return 1;
	}
	else{
		struct node *temp = top;
		top = top->next;
		free(temp);
		return 1;
	}
}
void print(){
	if(top == NULL)
	{
		printf("Stack is Empty");
	}
	else{
	struct node *index = top;
	while(index->next != NULL){
		printf("%d ", index->data);
		index = index->next;
	}
}
}

int peek(){
	if(top == NULL){
		printf("Stack is empty \n");
	}
	else{
	
	struct node *ptr = top;
	printf("top:%d ----------\n", ptr->data);
}
}




int main()
{
	int j,i;
for( j=0; j<=10;j++){

	for( i = 0;i<=j;i++){
	printf("i:%d j:%d \n",i,j);
	push(i);
}
}
pop();
pop();
peek();
print();
}
