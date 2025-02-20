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

Node *recursiveReverseLL(Node *head){
    if (head == nullptr || head->next == nullptr){ 
        return head;
    }

    Node *newHead = recursiveReverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
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
    vector<int> vec = {1,2,3,4};
    Node *head = convertArrayToLL(vec);
    head = recursiveReverseLL(head);
    printLL(head);

    return 0;
}