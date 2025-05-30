#include <stdio.h>

// Insertion Sort fonksiyonu
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Key de�erinden b�y�k olan elemanlar� bir ad�m sa�a kayd�r
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Diziyi yazd�rma fonksiyonu
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Orijinal dizi: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("S�ral� dizi: ");
    printArray(arr, n);

    return 0;
}

