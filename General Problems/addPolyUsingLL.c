#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coff;
    int power;
    struct Node *next;
} Node;

Node *createNode(int coff, int power){
    struct Node *nd = (Node *)malloc(sizeof(Node));
    nd->next = NULL;
    nd->coff = coff;
    nd->power = power;

    return nd;
}

Node *convertArrayToLL(int arr1[], int arr2[], int length){
    Node *head = createNode(arr1[0], arr2[0]);
    Node *mover = head;

    for(int i=1; i<length; i++){
        Node *temp = createNode(arr1[i], arr2[i]);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}

Node *insertAtTail(Node *head, int coff, int power){
    if (head == NULL){
        Node *temp = createNode(coff, power);
        return temp;        
    }

    Node *mover = head;

    while (mover->next){
        mover = mover->next;
    }

    Node *temp = createNode(coff, power);
    mover->next = temp;
}

Node *addPoly(Node *head1, Node *head2){
    Node *result = NULL;
    Node *mover1 = head1;
    Node *mover2 = head2;

    while (mover1 && mover2){
        if (mover1->power > mover2->power){
            result = insertAtTail(result, mover1->coff, mover1->power);
            mover1 = mover1->next;
        } else if (mover1->power < mover2->power){
            result = insertAtTail(result, mover2->coff, mover2->power);
            mover2 = mover2->next;
        } else{
            int sumCoff = mover1->coff + mover2->coff;

            if (sumCoff != 0){
                result = insertAtTail(result, sumCoff, mover1->power);
            }

            mover1 = mover1->next;
            mover2 = mover2->next;
        }
    }

    while (mover1){
        result = insertAtTail(result, mover1->coff, mover1->power);
        mover1 = mover1->next;
    }

    while (mover2){
        result = insertAtTail(result, mover2->coff, mover2->power);
        mover2 = mover2->next;
    }

    return result;
}

int main(){
    return 0;
}