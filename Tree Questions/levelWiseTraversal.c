#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform level-wise traversal
void levelWiseTraversal(Node* root) {
    if (root == NULL) {
        return; // If tree is empty
    }

    // Create a queue
    Node* queue[1000];
    int front = 0, rear = 0;

    // Enqueue root
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front; // Number of nodes in the current level

        // Process all nodes in the current level
        for (int i = 0; i < levelSize; i++) {
            Node* current = queue[front++];

            // Print the current node
            printf("%d ", current->data);

            // Enqueue left child
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }

            // Enqueue right child
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }

        // Print a newline to separate levels
        printf("\n");
    }
}

int main() {
    // Creating a sample tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Level-Wise Traversal:\n");
    levelWiseTraversal(root);

    return 0;
}
