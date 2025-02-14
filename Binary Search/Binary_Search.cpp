#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int size, int target){
	int low = 0;
	int high = size -1;
	while(low <= high){
		int mid = (low + high) / 2;
			if(arr[mid] == target){
				printf("Target index list[%d]", mid);
				return mid;
			}
			else if(arr[mid] > target){
				high = mid -1;
				printf("Mid: %d  \n", mid);
			}
			else if(arr[mid] < target){
				low = mid + 1;
				printf("Mid: %d  \n", mid);
			}
			else{
				printf("Target is not in the list");
				return -1;
			}
	}
}

int main(){
	int list[40];
	for(int i = 0; i <= 40;i++){
	list[i] = i; 
	}
	binary_search(list, 40, 3);
}
