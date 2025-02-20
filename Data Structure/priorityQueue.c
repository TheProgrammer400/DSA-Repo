#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;   // Pointer to the array that holds the elements
    int size;     // Current size of the priority queue
    int capacity; // Maximum capacity of the priority queue
} PriorityQueue;

// Create a new priority queue with a given capacity
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->array = (int*)malloc(capacity * sizeof(int));
    return pq;
}

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up: Restore heap property after insertion
void heapifyUp(PriorityQueue* pq, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (pq->array[parentIndex] > pq->array[index]) {
            swap(&pq->array[parentIndex], &pq->array[index]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

// Insert an element into the priority queue
void insert(PriorityQueue* pq, int value) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full!\n");
        return;
    }
    pq->array[pq->size] = value; // Add element at the end
    pq->size++;
    heapifyUp(pq, pq->size - 1); // Restore heap property
}

// Heapify Down: Restore heap property after extraction
void heapifyDown(PriorityQueue* pq, int index) {
    int smallest = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if (leftChildIndex < pq->size && pq->array[leftChildIndex] < pq->array[smallest]) {
        smallest = leftChildIndex;
    }
    if (rightChildIndex < pq->size && pq->array[rightChildIndex] < pq->array[smallest]) {
        smallest = rightChildIndex;
    }
    if (smallest != index) {
        swap(&pq->array[index], &pq->array[smallest]);
        heapifyDown(pq, smallest);
    }
}

// Extract the minimum element (highest priority)
int extractMin(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    int minValue = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return minValue;
}

// Free the memory allocated for the priority queue
void freePriorityQueue(PriorityQueue* pq) {
    free(pq->array);
    free(pq);
}

// Main function to test the priority queue
int main() {
    PriorityQueue* pq = createPriorityQueue(10);

    insert(pq, 5);
    insert(pq, 2);
    insert(pq, 8);
    insert(pq, 1);

    printf("Extracted min: %d\n", extractMin(pq)); // Should print 1
    printf("Extracted min: %d\n", extractMin(pq)); // Should print 2

    freePriorityQueue(pq);
    return 0;
}
