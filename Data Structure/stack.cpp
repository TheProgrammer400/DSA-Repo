#include<iostream>
using namespace std;

class Stack{
    int size;
    int *arr;
    int top;

    public:
        Stack(){
            size = 10;
            top = -1;
            arr = new int[size];
        }

        void push(int element){
            if (top == size-1){
                cout<<"Stack overflow!"<<endl;
            }

            top++;
            arr[top] = element;
        }

        int pop(){
            if (top == -1){
                cout<<"The stack is empty"<<endl;
            }

            int element = arr[top];
            top--;
            return element;
        }

        int Top(){
            return arr[top];
        }

        void print(){
            int ptr = top;

            while (top != -1){
                cout<<*(arr+ptr)<<" ";
                ptr--;
            }

            cout<<endl;
        }
};

int main(){
    Stack s1;
    s1.push(3);
    s1.push(4);
    s1.push(5);

    cout<<s1.pop()<<endl;
    return 0;
}