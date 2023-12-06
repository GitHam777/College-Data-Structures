#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && array[left] > array[largest]) {
        largest = left;
    }
    if(right < n && array[right] > array[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }
    for(int i = n - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

int main(void) {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d number of elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    heapSort(array, n);
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}