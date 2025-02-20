#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Stack{
    int size;
    int top;
    int *arr;

    public:
        Stack(){
            top = -1;
            size = 10;
            arr = new int[size];
        }

        void push(int element){
            if (top == size-1){
                return ;
            }

            arr[++top] = element;
        }

        int pop(){
            if (top == -1){
                return -1;
            }

            int popped = arr[top--];
            return popped;
        }
};

Node *convertArrayToLL(vector<int> vec){
    Node *head = new Node(vec[0]);
    Node *mover = head;

    for(int i=1; i<vec.size(); i++){
        Node *temp = new Node(vec[i]);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}

Node *reverseLLWithSpace(Node *head, Stack &s1){
    Node *mover = head;

    while (mover){
        s1.push(mover->data);
        mover = mover->next;
    }

    mover = head;

    while (mover){
        mover->data = s1.pop();
        mover = mover->next;
    }

    return head;
}

Node *reverseLL(Node *head){
    Node *temp = head;
    Node *prev = nullptr;

    while (temp){
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

void printLL(Node *head){
    Node *temp = head;

    while (temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

int main(){
    Stack s1;
    vector<int> vec = {1,2,3,4};
    Node *head = convertArrayToLL(vec);
    cout<<"Before reversel: ";
    printLL(head);
    head = reverseLLWithSpace(head, s1);
    cout<<"After reversel: ";
    printLL(head);

    return 0;
}