#include<stdio.h>

void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void selectionSort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        int minIndex = i;

        for(int j=i+1; j<size; j++){
            if (arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }

        swap(&arr[minIndex], &arr[i]);
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

    selectionSort(arr, size);
    printf("Array after sorting:\n");
    printArray(arr, size);
    return 0;
}