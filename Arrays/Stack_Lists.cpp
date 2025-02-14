#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int stack[MAX];

int top = -1;

void push(int data){
	if(top == MAX - 1){
		printf("Stack is full \n");
		return;
	}
	
	top++;
	stack[top] = data;
	printf("%d is added to stack \n");
}

int pop(){
	if (top == -1){
		printf("Stack is full \n");
		return -1;
	}
	int popped = stack[top];
	top--;
	printf("%d is poped up from stack \n");
	return popped;
}

int peek() {
 if (top == -1) {
 printf("Stack is empty \n");
 return -1;
 }
 return stack[top]; 
}

int main(){
push(10);
push(20); 
push(30); 
printf("Yýgnýn en ustundeki	eleman: %d\n", peek()); 
pop(); 
pop(); 
}
