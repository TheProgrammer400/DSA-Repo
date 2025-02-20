#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data){
            this->data = data;
            prev = nullptr;
            next = nullptr;
        }
};

Node *convertArrayToDLL(vector<int> vec){
    Node *head = new Node(vec[0]);
    Node *mover = head;

    for(int i=1; i<vec.size(); i++){
        Node *temp = new Node(vec[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}

Node *deleteHeadOfDLL(Node *head){
    if (head->next == nullptr || head == nullptr){
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;

    return head;
}

Node *deleteTailOfDLL(Node *head){
    if (head == nullptr || head->next == nullptr){
        return nullptr;
    }

    Node *mover = head;

    while (mover->next->next){
        mover = mover->next;
    }

    Node *front = mover->next;
    front->prev = nullptr;
    mover->next = nullptr;
    delete front;

    return head;
}

Node *deleteByIndex(Node *head, int index){
    if (head == nullptr){
        return nullptr;
    }

    if (index == 0){
        return deleteHeadOfDLL(head);
    }

    Node *mover = head;
    int count = 0;

    while (mover && count<index){
        mover = mover->next;
        count++;
    }

    if (mover->next == nullptr){
        return deleteTailOfDLL(head);
    }

    Node *back = mover->prev;
    Node *front = mover->next;

    back->next = front;
    front->prev = back;
    
    mover->next = nullptr;
    mover->prev = nullptr;
    delete mover;

    return head;
}

Node *insertAtHead(Node *head, int data){
    Node *temp = new Node(data);
    temp->next = head;
    temp->prev = nullptr;
    head->prev = temp;

    return temp;
}

Node *insertAtTail(Node *head, int data){
    Node *mover = head;

    while (mover->next){
        mover = mover->next;
    }

    Node *temp = new Node(data);
    mover->next = temp;
    temp->prev = mover;
    temp->next = nullptr;

    return head;
}

Node *insertAtIndex(Node *head, int index, int data){
    Node *mover = head;
    int count = 0;

    while (mover && count<index){
        mover = mover->next;
        count++;
    }

    if (mover->prev == nullptr){
        return insertAtHead(head, data);
    }

    if (mover->next == nullptr){
        return insertAtTail(head, data);
    }

    Node *temp = new Node(data);
    temp->prev = mover->prev;
    temp->next = mover;
    mover->prev->next = temp;
    mover->prev = temp;

    return head;
}

void printMiddle(Node *head){
    int i = 1;
    float j = 1;
    Node *mover = head->next;

    while(mover){
        mover = mover->next;
        i = i + 1;
        j = j + 0.5;
    }

    float index = j-1;
    int count = 0;
    mover = head;

    while (mover && count<(int)index){
        mover = mover->next;
        count++;
    }

    if (i % 2 == 1){
        cout<<mover->data;
    } else {
        cout<<mover->data<<" "<<mover->next->data<<endl;
    }
}

void printDLL(Node *head){

    Node *mover = head;

    while (mover){
        cout<<mover->data<<" ";
        mover = mover->next;
    }

    cout<<endl;
}

int main(){
    vector<int> vec = {1,2,3,4,5};
    Node *head = convertArrayToDLL(vec);
    cout<<"Before: ";
    printDLL(head);  
    cout<<"After: ";
    head = insertAtIndex(head, 0, 43);
    printDLL(head);  

    return 0;
}