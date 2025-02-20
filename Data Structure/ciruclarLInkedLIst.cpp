#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void traversing(struct Node *head){
    struct Node *ptr = head;

    do{
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    } while (ptr != head);
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 3;
    second->data = 5;
    third->data = 2;

    head->next = second;
    second->next = third;
    third->next = head;

    traversing(head);

    return 0;
}