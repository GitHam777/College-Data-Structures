#include <stdio.h>

void merge(int array[], int l, int r, int m) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = array[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, r, m);
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
    mergeSort(array, 0, n - 1);
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}