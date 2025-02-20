#include<stdio.h>

void insertionSort(int *arr, int size){
    int key, j;

    // considering 1st element to be sorted, that's why loop started from index 1

    for(int i=1; i<size; i++){
        key = arr[i]; // array element to be shifted
        j = i-1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j]; // shifting one element forward
            j--;
        }

        arr[j+1] = key;
    }
}

void printArray(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(){
    int arr[] = {4, 34, 54, 21, 67, 0, 34};
    int size = sizeof(arr)/sizeof(int);

    printf("Original array:\n");
    printArray(arr, size);

    insertionSort(arr, size);
    printf("Array after sorting:\n");
    printArray(arr, size);
    return 0;
}