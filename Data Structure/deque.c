#include<stdio.h>
#define size 50

typedef struct Deque{
    int front;
    int rear;
    int arr[size];
    int currSize;
} Deque;

void initialize(Deque* q1){
    q1->currSize = 0;
    q1->rear = -1;
    q1->front = -1;
}

int isEmpty(Deque* q1){
    if(q1->currSize == 0){
        return 1;
    }
    return 0;
}

int isFull(Deque* q1){
    if(q1->currSize == size){
        return 1;
    }
    return 0;
}

void insertFront(Deque* q1,int num){
    if(isFull(q1)){
        printf("Queue is Full\n");
        return;
    }

    if(isEmpty(q1)){
        q1->front = q1->rear = 0;
    } else{
        q1->front = (q1->front+size-1)%size;
    }
    
    q1->currSize++;
    q1->arr[q1->front] = num;
}

void insertRear(Deque* q1,int num){
    if(isFull(q1)){
        printf("Queue is Full\n");
        return;
    }
    
    if(isEmpty(q1)){
        q1->front = q1->rear = 0;
    } else {
        q1->rear = (q1->rear+1) % size;
    }

    q1->currSize++;
    q1->arr[q1->rear] = num;
}
void deleteFront(Deque* q1){
    if(isEmpty(q1)){
        printf("Queue is Empty\n");
        return;
    }

    printf("Element %d is dequeued\n",q1->arr[q1->front]);

    if(q1->front == q1->rear){
        q1->rear = q1->front = -1;
    } else{
        q1->front = (q1->front+1)%size;
    }

    q1->currSize--;
    return;
}

void deleteRear(Deque* q1){
    if(isEmpty(q1)){
        printf("Queue is Empty\n");
        return;
    }

    printf("Element %d is dequeued\n",q1->arr[q1->rear]);

    if(q1->rear == q1->front){
        q1->rear = q1->front = -1;
    }
    else{
        q1->rear = (q1->rear+size-1)%size;
    }
    q1->currSize--;
}

void display(Deque* q1){
    if(isEmpty(q1)){
        printf("Queue is Empty\n");
        return;
    }
    for(int i = q1->front;i!=q1->rear;i = (i+1)%size){
        printf("%d ",q1->arr[i]);
    }
    printf("%d\n",q1->arr[q1->rear]);
    return;
}
int main(){
    Deque q1;
    initialize(&q1);
    insertFront(&q1,1);
    insertFront(&q1,2);
    insertRear(&q1,3);
    deleteFront(&q1);
    deleteRear(&q1);
    display(&q1);
    return 0;
}