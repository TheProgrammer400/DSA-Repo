#include <stdio.h>
#include <stdlib.h>

// Define the structure and use typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning\n", data);
}

// Function to insert a node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end\n", data);
}

// Function to insert a node at a specific position
void insertAtPosition(Node** head, int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", data, position);
}

// Function to delete a node from the beginning
void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted node from the beginning\n");
}

// Function to delete a node from the end
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("Deleted the only node in the list\n");
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("Deleted node from the end\n");
}

// Function to delete a node at a specific position
void deleteAtPosition(Node** head, int position) {
    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted node at position %d\n", position);
}

// Function to search for a node in the list
int search(Node* head, int key) {
    int position = 1;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// Function to reverse the linked list
void reverse(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    printf("Reversed the linked list\n");
}

// Function to traverse and print the linked list
void traverse(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 2);
    traverse(head);

    deleteAtBeginning(&head);
    traverse(head);

    deleteAtEnd(&head);
    traverse(head);

    insertAtEnd(&head, 25);
    insertAtEnd(&head, 30);
    traverse(head);

    deleteAtPosition(&head, 2);
    traverse(head);

    int key = 25;
    int position = search(head, key);
    if (position != -1) {
        printf("Element %d found at position %d\n", key, position);
    } else {
        printf("Element %d not found in the list\n", key);
    }

    reverse(&head);
    traverse(head);

    return 0;
}