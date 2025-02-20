#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int i=low;
    int j=high;

    while (i<j){
        while (arr[i] <= pivot && i<=high-1){
            i++;
        }

        while (arr[j] > pivot && j>=low){
            j--;
        }

        if (i<j){
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int *arr, int low, int high){
    if (low < high){
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}

void printArray(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int size = sizeof(arr)/sizeof(int);

    printf("Sorted array:\n");
    quickSort(arr, 0, size-1);
    printArray(arr, size);

    return 0;
}