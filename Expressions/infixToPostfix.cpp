#include<iostream>
using namespace std;

int priority(char letter){
    if (letter == '^'){
        return 3;
    } else if (letter == '/' || letter == '*'){
        return 2;
    } else if (letter == '+' || letter == '-'){
        return 1;
    } else{
        return -1;
    }
}

class Stack{
    int size;
    char *arr;
    int top;

    public:
        Stack(){
            top = -1;
            size = 50;
            arr = new char[size];
        }

        void push(char element){
            if (top == size-1){
                cout<<"Stack overflow!"<<endl;
                return;
            }

            top++;
            arr[top] = element;
        }

        void pop(){
            if (top == -1){
                cout<<"Stack underflow"<<endl;
                return;
            }

            top--;
        }

        char Top(){
            return arr[top];
        }

        bool empty(){
            if (top == -1){
                return true;
            } else{
                return false;
            }
        }
};

int main(){
    Stack s1;
    string expression;
    cout<<"Enter the expression: ";
    cin>>expression;
    string result = "";

    int length = expression.size();

    for(int i=0; i<length; i++){
        char character = expression.at(i);

        if (character >= 'a' && character <= 'z' || 
        character >= 'A' && character <= 'Z' || 
        character >= '0' && character <= '9'){

            // character is operand
            result = result + character;

        } else if (character == '('){
            s1.push(character);
        } else if (character == ')'){
            while (!s1.empty() && s1.Top() != '('){
                result = result + s1.Top();
                s1.pop();
            }

            s1.pop(); // to remove the '('
        } else {
            while (!s1.empty() && priority(character) <= priority(s1.Top())){
                result = result + s1.Top();
                s1.pop();
            }

            s1.push(character);
        }
    }

    // iterated over the whole string, now checking if the stack is empty or not
    // if not empty then add all the elements of stack in the 'result' as per the LIFO

    while (!s1.empty()){
        result = result + s1.Top();
        s1.pop();
    }

    cout<<result<<endl;
    return 0;
}