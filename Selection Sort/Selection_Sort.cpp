#include <stdio.h>
#include <stdlib.h>

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

int* selection_sort(int *arr, int size){
	
	int min;
	printf("Original Array: ");
	show(arr, size);
	printf("\n \n");
	
	for(int j = 0; j  < size - 1 ; j++){
		min = j;		
		for(int i = j + 1; i < size  ;i++){
			if(arr[i] < arr[min]){
				min = i;
			}
		}
		printf("Sorting: ");
			show(arr, size);
			printf(" Min Value:%d Index[%d]",arr[min], min);
			swap(&arr[j], &arr[min]);
			printf("\n");
	}
	printf("\n \n");
	return arr;

}

int main(){
int array[10] = {5,3,7,1,4,9,47,85,21,10};

 selection_sort(array, 10);
 printf("Final Array: ");
 show(array, 10);

}
