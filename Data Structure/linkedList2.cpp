#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

    public:
        Node(int data, Node *ptr){
            this->data = data;
            next = ptr;
        }

        Node(int data){
            this->data = data;
            next = nullptr;
        }
};

Node *convertArrayToLL(vector<int> arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for(int i=1; i<arr.size(); i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // or it can be written as 'mover = mover->next'
    }

    return head;  // returning the main pointer which is 'head'
}


int getLength(Node *head){
    int count = 0;

    Node *temp = head;

    while (temp){
        count++;
        temp = temp->next;
    }

    return count;
}

bool search(Node *head, int target){
    Node *temp = head;
    bool found = false;

    while (temp){
        if (temp->data != target){
            temp = temp->next;
        } else {
            return true;
        }
    }

    return false;
}

Node *removeHead(Node *head){
    if (head == nullptr){
        return head;
    }

    Node *temp = head;

    head = head->next;
    delete temp; // or it can be written as 'free(temp)'
    return head;
}

Node *removeTail(Node *head){
    if (head == nullptr || head->next == nullptr){
        return nullptr;
    }

    Node *temp = head;

    while ((temp->next)->next){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *removeNode(Node *head, int index){
    if (index == 0){
        return removeHead(head);
    }

    int count = 0;
    Node *temp = head;

    while (temp && count != index-1){
        count++;
        temp = temp->next;

        if (temp == nullptr){
            return head;
        }
    }

    Node *temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;

    return head;
}

void traverse(Node *head){
    Node *temp = head;

    while (temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

Node *removeNodeByValue(Node *head, int element){
    
}

int main(){
    vector<int> arr= {1,2,3,4,5,6,7,8};

    Node *head = convertArrayToLL(arr);

    int length = getLength(head);
    // cout<<"The length of the LL is: "<<length<<endl;

    // head = removeHead(head);  --> to remove the first node of the LL
    // head = removeTail(head);  --> to remove the last node of the LL
    head = removeNode(head, 0);
    traverse(head);

    return 0;
}