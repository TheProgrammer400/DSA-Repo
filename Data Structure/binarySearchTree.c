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

Node *findMin(Node *root){
    while (root->left){
        root = root->left;
    }

    return root;
}

// using single pointer

/*

Node *deleteNode(Node *root, int key){
    if (root == NULL){
        return NULL;
    }

    if (root->data > key){
        root->left = deleteNode(root->left, key);
    } else if (root->data < key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        } else if (root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        } else {
            Node *temp = findMin(root->right);
            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

*/

// using double pointer

void deleteNode(Node **root, int key){
    if (*root == NULL){
        return ;
    }

    if ((*root)->data > key){
        deleteNode(&((*root)->left), key);
    } else if ((*root)->data < key){
        deleteNode(&((*root)->right), key);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL){
            free(*root);
            *root = NULL;
            return;
        } else if ((*root)->left == NULL){
            Node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return;
        } else if ((*root)->right == NULL){
            Node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return ;            
        } else {
            Node *temp = findMin((*root)->right);
            (*root)->data = temp->data;

            deleteNode(&((*root)->right), temp->data); // deleting the in-order successor
        }
    }
}

Node *binarySearch(Node *root, int data){
    if (root == NULL){
        return NULL;
    } 

    if (root->data > data){
        return binarySearch(root->left, data);
    } else if (root->data < data){
        return binarySearch(root->right, data);
    } else {
        return root;
    }
}

// max is 2^31 (max int value)
// min is -2^31 - 1 (min int value)

int isValidBST(Node *root, int min, int max){
    if (root == NULL){
        return 1;
    } else {
        if (root->data < min || root->data > max){
            return 0;
        } else {
            return isValidBST(root->left, min, root->data) && isValidBST(root->right, root->data, max);
        }
    }
}

int findHeight(Node *root){
    if (root == NULL){
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    if (rightHeight > leftHeight){
        return rightHeight + 1;
    } else {
        return leftHeight + 1;
    }
}

Node *inOrderSuccessor(Node *root, Node *reqNode){
    Node *successor = NULL;

    while (root){
        if (root->data <= reqNode->data){
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }

    return successor;
}

void kThMinimumHelper(Node *root, int k, int *count, int *result){
    if (root == NULL || k <= *count){
        return ;
    }

    kThMinimumHelper(root->left, k, count, result);
    (*count)++;

    if (*count == k){
        *result =  root->data;
        return ;
    }

    kThMinimumHelper(root->right, k, count, result);
}

/*

following function returns kth minimum node instead of value:

    void traversal(Node *root, int *count, int k, Node **result){
        if (root == NULL){
            return ;
        }

        traversal(root->left, count, k, result);
        (*count)++;

        if (k == *count){
            *result = root;
            // return;
        }

        traversal(root->right, count, k, result);
    }

    Node *kThMinimumElement(Node *root, int k){
        if (k <= 0){
            return root;
        }

        int count = 0;
        Node *kThNode = NULL;
        traversal(root, &count, k, &kThNode);
        return kThNode;
    }
*/

int findKthMinimum(Node *root, int k){
    int count = 0;
    int result = -1;

    kThMinimumHelper(root, k, &count, &result);
    return result;
}

Node *findFloor(Node *root, int key){
    // floor value of a given key is the largest value in the BST that is less than or equal to the given key.

    Node *floor = NULL;

    while (root){
        if (root->data == key){
            floor = root;
            return floor;
        }

        if (root->data < key){
            floor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return floor;
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
    Node *root = NULL;
    insertNode(&root, 12);
    insertNode(&root, 1);
    insertNode(&root, 10);

    return 0;
}