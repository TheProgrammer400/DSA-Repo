#include<iostream>
using namespace std;

class Stack{
    int size;
    int top;
    char *arr;

    public:
        Stack(){
            size = 30;
            top = -1;
            arr = new char[size];
        }

        void push(int element){
            if (top == size-1){
                cout<<"Stack overflow!"<<endl;
                return ;
            }

            arr[++top] = element;
        }

        char pop(){
            if (top == -1){
                cout<<"Stack underflow!"<<endl;
                return -1;
            }

            int element = arr[top--];
            return element;
        }

        char Top(){
            return arr[top];
        }

        bool empty(){
            if (top == -1){
                return true;
            }

            return false;
        }
};

bool bracketCheck(string expression, Stack &s1){
    int length = expression.size();

    for(int i=0; i<length; i++){
        char letter = expression[i];

        if (letter == '(' || letter == '[' || letter == '{'){
            s1.push(letter);
        } else {
            if (s1.empty()){
                return false;
            }

            char lastElement = s1.pop();

            if (letter == ')' && lastElement == '(' ||
                letter == '}' && lastElement == '{' || 
                letter == ']' && lastElement == '['){
                    continue;
            } else {
                return false;
            }
        }
    }

    return s1.empty();
}

int main(){
    Stack s1;

    string expression;
    cout<<"Enter the expression: ";
    cin>>expression;

    if (bracketCheck(expression, s1)){
        cout<<"The Parentheses are balanced"<<endl;
    } else {
        cout<<"The Parentheses are not balanced"<<endl;
    }

    return 0;
}