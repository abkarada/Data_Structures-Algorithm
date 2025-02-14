#include <stdio.h>

int linear_serach(int arr[], int size, int target){
	for(int i = 0; i < size; i++){
		if(arr[i] == target){
			return i;
		}
	}
	return -1;
}
/*Best Case -> O(1)
  Mid Case -> O(n)
  Worst Case->O(n)
  */
  
