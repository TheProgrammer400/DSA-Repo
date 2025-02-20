#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int size;
    int start, end;
    int *arr;
    int currSize;

    public:
        Queue(){
            start = end = -1;
            size = 20;
            arr = new int[size];
            currSize = 0;
        }

        void enqueue(int element){
            if (currSize == size){
                cout<<"Queue is full!"<<endl;
                return ;
            } 
            
            if (end == -1){
                start = end = 0;
            } else {
                end = (end + 1) % size;
            }

            arr[end] = element;
            currSize++;
        }

        int dequeue(){
            if (start == -1){
                cout<<"Queue is empty!"<<endl;
            }

            int popped = arr[start];

            if (currSize == 1){
                start = -1;
                end = -1;
            } else{
                start = (start+1) % size;
            }

            currSize--;
            return popped;
        }

        int getSize(){
            return currSize;
        }
};

int main(){
    return 0;
}