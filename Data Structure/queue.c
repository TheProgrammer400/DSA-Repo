#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int size;
    int start, end;
    int *arr;
    int currSize;
} Queue;

// Constructor equivalent in C
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->start = q->end = -1;
    q->size = 20;
    q->arr = (int*)malloc(q->size * sizeof(int));
    q->currSize = 0;
    return q;
}

// Enqueue function
void enqueue(Queue *q, int element) {
    if (q->currSize == q->size) {
        printf("Queue is full!\n");
        return;
    }

    if (q->end == -1) {
        q->start = q->end = 0;
    } else {
        q->end = (q->end + 1) % q->size;
    }

    q->arr[q->end] = element;
    q->currSize++;
}

// Dequeue function
int dequeue(Queue *q) {
    if (q->start == -1) {
        printf("Queue is empty!\n");
        return -1; // Return -1 as an indication of error
    }

    int popped = q->arr[q->start];

    if (q->currSize == 1) {
        q->start = -1;
        q->end = -1;
    } else {
        q->start = (q->start + 1) % q->size;
    }

    q->currSize--;
    return popped;
}

// Get current size of the queue
int getSize(Queue *q) {
    return q->currSize;
}

int main() {
    Queue *q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue size: %d\n", getSize(q));

    free(q->arr);
    free(q);

    return 0;
}
