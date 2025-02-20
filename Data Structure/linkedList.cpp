#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void traversing(struct Node *ptr){
    while (ptr != NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

/*

struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

had to comment this code as a generalized function is 
written for inserting element at any index

*/

struct Node *insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (index == 0){
        ptr->next = head;
        return ptr;
    }

    struct Node *fls = head;
    
    for(int i=0; i<index-1; i++){
        fls = fls->next;
    }

    ptr->next = fls->next;
    fls->next = ptr;
    return head;
}

/*

struct Node *deleteFirst(struct Node *head){
    // struct Node *ptr = head->next;
    // free(head);
    // return ptr;

    // or can be done like this

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

generalized function is written below

*/

struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *ptr = head;

    if (index == 0){
        ptr = head->next;
        free(ptr);
        return head;
    } else{
        struct Node *fls = head->next;

        for(int i=0; i<index-1; i++){
            ptr = ptr->next;
            fls = fls->next;
        }

        ptr->next = fls->next;
        free(fls);
        return head;
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    second->data = 4;
    third->data = 7;

    head->next = second;
    second->next = third;
    third->next = NULL;

    cout<<"Before:"<<endl;
    traversing(head);
    cout<<"After:"<<endl;
    head = insertAtIndex(head, 12, 1);
    traversing(head);

    return 0;
}