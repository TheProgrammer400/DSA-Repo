#include<stdio.h>
#include<limits.h>

int maxSubArraySum(int *arr, int size){
    int sum = 0;
    int max = INT_MIN;

    for(int i=0; i<size; i++){
        sum = sum + arr[i];

        if (max < sum){
            max = sum;
        }

        if (sum < 0){
            sum = 0;
        }
    }

    if (max < 0){
        max = 0;
    }

    // have to write above if-else condition if 
    // in question, it mentions that also find the empty array

    return max;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr)/sizeof(int);

    int maxSum = maxSubArraySum(arr, size);
    printf("Maximum sub array sum: %d\n", maxSum);

    return 0;
}