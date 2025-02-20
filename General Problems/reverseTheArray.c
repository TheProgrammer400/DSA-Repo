#include<stdio.h>

// this is similar to quicksort algorithm

void swap(int *n1, int *n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void reverse(int *arr, int low, int high){
    if (low < high){
        int i=low;
        int j=high;

        swap(&arr[i], &arr[j]);
        i++;
        j--;
        
        if (low < high){
            reverse(arr, i, j);
        }
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);

    reverse(arr, 0, size-1);

    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}