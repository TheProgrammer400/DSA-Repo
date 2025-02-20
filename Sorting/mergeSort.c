#include<stdio.h>

void merge(int *arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;

    int temp[high+1];
    int index = 0;

    // merging two sorted arrays

    while (left <= mid && right <= high){
        if (arr[left] > arr[right]){
            temp[index++] = arr[right];
            right++;
        } else{
            temp[index++] = arr[left];
            left++;
        }
    }

    while (left <= mid){
        temp[index++] = arr[left];
        left++;
    }

    while (right <= high){
        temp[index++] = arr[right];
        right++;
    }

    // copying all the elements from temp array to original array

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(int *arr, int low, int high){
    if (low == high){
        return;
    }

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void printArray(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(){
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int size = sizeof(arr)/sizeof(int);

    printf("Sorted array:\n");
    mergeSort(arr, 0, size-1);
    printArray(arr, size);

    return 0;
}