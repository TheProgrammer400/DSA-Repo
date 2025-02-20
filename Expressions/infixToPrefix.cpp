#include<iostream>
using namespace std;

class Stack{
    int size;
    int top;
    char *arr;

    public:
        Stack(){
            size = 20;
            top = -1;
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
                cout<<"Stack underflow!"<<endl;
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
            }

            return false;
        }
};

void change(char *c1, char *c2){
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

int priority(char letter){
    if (letter == '^'){
        return 3;
    } else if (letter == '*' || letter == '/'){
        return 2; 
    } else if (letter == '+' || letter == '-'){
        return 1;
    } else {
        return -1;
    }
}

string reverseExp(string expre, int low, int high){
    int left=low;
    int right=high;

    while (left < right){

        change(&expre[left], &expre[right]);
        left++;
        right--;
    }

    string result = "";

    for(int i=0; i<expre.size(); i++){
        char letter = expre[i];

        if (letter == '('){
            result = result + ')';
        } else if (letter == ')') {
            result = result + '(';
        } else {
            result = result + letter;
        }
    }

    return result;
}

string infixToPrefix(string expre, Stack &s1){
    string expression = reverseExp(expre, 0, expre.size()-1);
    string result = "";

    for(int i=0; i<expression.size(); i++){
        char letter = expression.at(i);

        if (letter >= 'A' && letter <= 'Z' ||
            letter >= 'a' && letter <= 'z' || 
            letter >= '0' && letter <= '9'){
                result = result + letter;

        } else if (letter == '('){
            s1.push(letter);
        } else if (letter == ')') {
            while (!s1.empty() && s1.Top() != '('){
                result = result + s1.Top();
                s1.pop();
            }

            s1.pop(); // to remove ')'
        } else {
            if (letter == '^'){
                while (!s1.empty() && priority(letter) <= priority(s1.Top())){
                    // basically, this condition states that,
                    // we can't store two '^' at the same time

                    result = result + s1.Top();
                    s1.pop();
                }
            } else {
                while (!s1.empty() && priority(letter) < priority(s1.Top())){
                    result = result + s1.Top();
                    s1.pop();
                }
            }

            s1.push(letter);
        }
    }

    while (!s1.empty()){
        result = result + s1.Top();
        s1.pop();
    }

    return reverseExp(result, 0, result.size()-1);
}

int main(){
    Stack s1;
    string expression;

    cout<<"Enter the expression: ";
    cin>>expression;

    cout<<"The result is: "<<infixToPrefix(expression, s1)<<endl;

    return 0;
}