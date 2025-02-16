#include <stdio.h>

#define MAX 10

void merge(int *A, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int c[MAX]; // Geçici dizi

    // Küçükten büyüðe sýralama
    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            c[k++] = A[i++];
        } else {
            c[k++] = A[j++];
        }
    }

    // Kalan elemanlarý ekle
    while (i <= mid) {
        c[k++] = A[i++];
    }
    while (j <= high) {
        c[k++] = A[j++];
    }

    // Sýralanmýþ geçici diziyi geri kopyala
    for (i = low; i <= high; i++) {
        A[i] = c[i];
    }
}

void mergeSort(int *A, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main() {
    int arr[MAX] = {8, 1, 4, 9, 2, 0, 3, 6, 7, 5};

    printf("Array before sorting:\n");
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, MAX - 1);

    printf("Array after sorting:\n");
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

