#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;
int size = 0;

void addStack(int data){
	arr = (int *)realloc(arr,(size + 1)*sizeof(int));
	arr[size] = data;
	size++;
	for(int i = 0; i < size/2; i++ ){
		int ptr;
		ptr = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size -1 - i ] = ptr;
	}
	
}

void print(){
	for(int i = 0; i < size  ; i++){
		printf("%d ", arr[i]);
	}
}
int main(){
	 addStack(1);
	 addStack(2);
	 addStack(3);
	 addStack(4);
 	print();
 	free(arr);
	
}
