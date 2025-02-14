#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void show(int *array, int size){
	int i;
	for(i = 0; i< size ;i++){
		printf("%d ", array[i]);
	}
}

int* bubble_sort(int *arr, int size){
	int i, j;
	printf("Original Array: ");
	show(arr, size);
	printf("\n \n");

		
	for(j = 0; j < size  ; j++){
		
		for( i = 0; i < size - 1 ;i++){
		
			if(arr[i] > arr[i + 1]){
				printf("Sorting: ");
				swap(&arr[i], &arr[i + 1]);
				show(arr, size);
				printf("\n");
			}
		}
	}
	 printf("\n \n");

	return arr;
}



int main(){

int array[5] = {5, 8, 4, 1,0};
 
 bubble_sort(array, 5);
 printf("Final Array: ");
 show(array, 5);
	
	

}
