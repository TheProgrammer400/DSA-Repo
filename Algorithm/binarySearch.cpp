#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    mid = (low + high) / 2;

    while(low <= high){
        if (arr[mid] == element){
            return mid;
        } else {
            if (element > arr[mid]){
                low = mid+1;
                mid = (low + high) / 2;
            } else{
                high = mid-1;
                mid = (low+high) / 2;
            }
        }
    }
    return -1;    
}

int main(){
    int arr[] = {1,23,34,45,56,68};
    int size = sizeof(arr) / sizeof(int);
    int element = 1;
    int index = binarySearch(arr, size, element);

    if (index >= 0){
        cout<<element<<" found at index "<<index<<endl;
    } else{
        cout<<element<<" is not present in the array!"<<endl;
    }

    return 0;
}