#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int n) {
    int min_index;
    for(int i = 0; i < n - 1; i++) {
        min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(&array[min_index], &array[i]);
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
    selectionSort(array, n);
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}