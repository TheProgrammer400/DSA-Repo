#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;   // Pointer to the array that holds the heap elements
    int size;     // Current size of the heap
    int capacity; // Maximum capacity of the heap
} MinHeap;

// Function to create a new min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up: Maintain the heap property after insertion
void heapifyUp(MinHeap* heap, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap->array[parentIndex] > heap->array[index]) {
            swap(&heap->array[parentIndex], &heap->array[index]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

// Insert a new element into the heap
void insert(MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        return;
    }
    heap->array[heap->size] = value; // Insert the new element at the end
    heap->size++;
    heapifyUp(heap, heap->size - 1); // Restore the heap property
}

// Heapify Down: Maintain the heap property after extraction
void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    // Compare with left child
    if (leftChildIndex < heap->size && heap->array[leftChildIndex] < heap->array[smallest]) {
        smallest = leftChildIndex;
    }
    // Compare with right child
    if (rightChildIndex < heap->size && heap->array[rightChildIndex] < heap->array[smallest]) {
        smallest = rightChildIndex;
    }
    // If the smallest is not the current index, swap and heapify down
    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Extract the minimum element from the heap
int extractMin(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty!\n");
        return -1; // Return an invalid value
    }

    int minValue = heap->array[0]; // Get the minimum value
    heap->array[0] = heap->array[heap->size - 1]; // Move the last element to the root
    heap->size--; // Reduce the size of the heap
    heapifyDown(heap, 0); // Restore the heap property
    return minValue; // Return the minimum value
}

// Function to free the memory allocated for the heap
void freeMinHeap(MinHeap* heap) {
    free(heap->array);
    free(heap);
}

// Main function for testing the heap implementation
int main() {
    MinHeap* heap = createMinHeap(10); // Create a heap with capacity 10

    insert(heap, 3);
    insert(heap, 1);
    insert(heap, 4);
    insert(heap, 10);
    insert(heap, 2);

    printf("Extracted min: %d\n", extractMin(heap)); // Should print 1
    printf("Extracted min: %d\n", extractMin(heap)); // Should print 2
    printf("Extracted min: %d\n", extractMin(heap)); // Should print 3

    freeMinHeap(heap); // Free the allocated memory
    return 0;
}
