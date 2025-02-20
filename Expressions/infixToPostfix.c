#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int size;
    char *arr;
    int top;
} Stack;

void init(Stack *s1){
    s1->size = 20;
    s1->arr = (char *)malloc(sizeof(char) * s1->size);
    s1->top = -1;
}

void push(Stack *s1, char data){
    if (s1->top == s1->size - 1){
        return ;
    }

    s1->arr[++s1->top] = data;
}

char pop(Stack *s1){
    if (s1->top == -1){
        return '\0';
    }

    return s1->arr[s1->top--];
}

int isEmpty(Stack *s1){
    return s1->top == -1;
}

char Top(Stack *s1){
    return s1->arr[s1->top];
}

void addChar(char **word, int *size, char letter){
    (*word)[*size] = letter;
    (*word)[*size+1] = '\0';
    (*size)++;
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

void infixToPostfix(char *expression){
    int length = strlen(expression);
    int index = 0;

    Stack s1;
    init(&s1);

    char *result = (char *)malloc(sizeof(char) * (length+10));
    result[0] = '\0';

    for(int i=0; i<length; i++){
        char letter = expression[i];

        if (letter >= 'a' && letter <= 'z' || 
            letter >= 'A' && letter <= 'Z' || 
            letter >= '0' && letter <= '9'){
                addChar(&result, &index, letter);
        } else if (letter == '('){
            push(&s1, letter);
        } else if (letter == ')'){
            while (!isEmpty(&s1) && Top(&s1) != '('){
                char top = pop(&s1);
                addChar(&result, &index, top);
            }

            pop(&s1);
        } else {
            while (!isEmpty(&s1) && priority(Top(&s1)) >= priority(letter)){
                char top = pop(&s1);
                addChar(&result, &index, top);
            }

            push(&s1, letter);
        }
    }

    while (!isEmpty(&s1)){
        char top = pop(&s1);
        addChar(&result, &index, top);
    }
}

int main(){
    return 0;
}