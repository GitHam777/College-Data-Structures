#include <stdio.h>

void insertionSort(int array[], int n) {
    int key;
    for(int i = 1; i < n; i++) {
        int j;
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
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
    insertionSort(array, n);
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}