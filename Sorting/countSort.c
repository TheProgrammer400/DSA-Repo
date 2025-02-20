#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

int maximum(int *arr, int size){
    int max = arr[0];
    for(int i=0; i<size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

void countSort(int *arr, int size){
    int max = maximum(arr, size);
    int *count = (int *)calloc((max+1), sizeof(int)); // also initilized to 0

    for(int i=0; i<size; i++){
        count[arr[i]]++;
    }

    int index = 0;

    for(int i=0; i<max+1; i++){
        while(count[i] > 0){
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main(){
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int size = sizeof(arr)/sizeof(int);
    countSort(arr, size);
    printArray(arr, size);

    return 0;
}

