#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// using single pointer

// Node *insertNode(Node *root, int data){
//     if (root == NULL){
//         return createNode(data);
//     }
    
//     if (data > root->data){
//         root->right = insertNode(root->right, data);
//     } else {
//         root->left = insertNode(root->left, data);
//     }

//     return root;
// }

// using double pointer

void insertNode(Node **root, int data){
    if (*root == NULL){
        *root = createNode(data);
        return ;
    }

    if ((*root)->data > data){
        insertNode(&((*root)->left), data);
    } else {
        insertNode(&((*root)->right), data);
    }
}

Node *convertArrayToBST(int arr[], int length){
    Node *root = createNode(arr[0]);

    for(int i=1; i<length; i++){
        insertNode(&root, arr[i]);
    }

    return root;
}

int findHeight(Node *root){
    if (root == NULL){
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    if (leftHeight > rightHeight){
        return leftHeight+1;
    } else {
        return rightHeight+1;
    }
}

void preOrderTraversal(Node *root){
    if (root == NULL){
        return ;
    }

    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root){
    if (root == NULL){
        return ;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root){
    if (root == NULL){
        return ;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main(){
    int arr[] = {4,3,2,6,8};
    int n = sizeof(arr) / sizeof(int);
    Node *root = convertArrayToBST(arr, n);

    return 0;
}