#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *convertArrayToLL(int arr[], int length){
    if (length == 0){
        return NULL;
    }

    Node *head = (Node *)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = NULL;

    Node *mover = head;

    for(int i=1; i<length; i++){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = arr[i];
        mover->next = temp;
        mover = mover->next;
        mover->next = NULL;
    }

    return head;
}

Node *insertAtHead(Node *head, int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;

    temp->next = head;
    return temp;
}

Node *insertTail(Node *head, int data){
    if (head == NULL){
        return insertAtHead(head, data);
    }

    Node *mover = head;

    while (mover->next){
        mover = mover->next;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    mover->next = temp;
    temp->next = NULL;

    return head;
}


Node *insertAtIndex(Node *head, int data, int index){
    if (index == 0){
        return insertAtHead(head, data);
    }

    Node *mover = head;
    int count = 0;

    while (mover && count<index-1){
        mover = mover->next;
        count++;
    }

    if (mover == NULL){
        return head;
    }

    if (mover->next == NULL){
        return insertTail(head, data);
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = mover->next;
    mover->next = temp;
    
    return head;
}

Node *deleteHead(Node *head){
    if (head == NULL){
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

Node *removeTail(Node *head){
    if (head == NULL){
        return NULL;
    }

    if (head->next == NULL){
        free(head);
        return NULL;
    }

    Node *mover = head;

    while (mover->next->next){
        mover = mover->next;
    }

    free(mover->next);
    mover->next = NULL;
    return head;
}

Node *deleteAtIndex(Node *head, int index){
    if (index == 0){
        return deleteHead(head);
    }

    if (head == NULL){
        return NULL;
    }

    Node *mover = head;
    int count = 0;

    while (mover && count<index-1){
        mover = mover->next;
        count++;
    }

    if (mover == NULL){
        return head;
    }

    Node *temp = mover->next;
    mover->next = mover->next->next;
    temp->next = NULL;
    free(temp);

    return head;
}

void printLL(struct Node *head){
    Node *mover = head;

    while (mover){
        printf("%d ", mover->data);
        mover = mover->next;
    }

    printf("\n");
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(int);
    Node *head = convertArrayToLL(arr, n);
    printf("Before: ");
    printLL(head);
    printf("After: ");
    head = deleteAtIndex(head, 2);
    printLL(head);

    return 0;
}