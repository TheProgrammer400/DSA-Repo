#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int *arr;
    int top;
    int size;
};

void stackInit(struct Stack *s){
    s->size = 30;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    s->top = -1;
}

void push(struct Stack *s, int element){
    if (s->top == s->size-1){
        printf("Stack overflow!\n");
        return ;
    }

    s->arr[++s->top] = element;
}

int pop(struct Stack *s){
    if (s->top == -1){
        return -1;
    }

    int popped = s->arr[s->top--];
    return popped;
}

int Top(struct Stack *s){
    return s->arr[s->top];
}

int empty(struct Stack *s){
    if (s->top == -1){
        return 1;
    } else {
        return 0;
    }
}

int postfixEvaluation(struct Stack *s1, char expression[], int length){
    for(int i=0; i<length; i++){
        char letter = expression[i];

        if (letter >= '0' && letter <= '9'){
            // the letter is number
            int num = letter - '0';
            push(s1, num);
        } else if (letter == ' '){
            continue;
        } else {
            // get 2 top elements of the stack

            int n2 = pop(s1);
            int n1 = pop(s1);
            int n3;

            if (letter == '+'){
                n3 = n1 + n2;
            } else if (letter == '-'){
                n3 = n1 - n2;
            } else if (letter == '*'){
                n3 = n1 * n2;
            } else if (letter == '/'){
                n3 = n1 / n2;
            }

            push(s1, n3);
        }
    }

    return pop(s1);
}

int main(){
    struct Stack s1;
    stackInit(&s1);

    char expression[30];
    printf("Enter the expression: ");
    // fgets(expression, 30, stdin);
    scanf("%s", expression);

    int length = strlen(expression);
    int result = postfixEvaluation(&s1, expression, length);

    printf("The result of the postFix evaluation is: %d\n", result);
    return 0;
}