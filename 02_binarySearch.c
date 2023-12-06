#include <stdio.h>

int binarySearch(int array[], int begin, int end, int value) {
    int mid;
    if(end >= begin) {
        mid = (begin + end) / 2;
        if(array[mid] == value) {
            return mid + 1;
        }
        else if(array[mid] < value) {
            return binarySearch(array, mid + 1, end, value);
        }
        else {
            return binarySearch(array, begin, mid - 1, value);
        }
    }
    return -1;
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
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);
    int result = binarySearch(array, 0, n - 1, value);
    if(result == -1) {
        printf("Element not found");
    }
    else {
        printf("Element found at position: %d", result);
    }
    return 0;
} 