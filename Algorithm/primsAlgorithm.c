#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Node {
    int data;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adjList;
} Graph;

typedef struct PQNode {
    int vertex;
    int weight;
} PQNode;

typedef struct PriorityQueue {
    PQNode* nodes;
    int size;
    int capacity;
} PriorityQueue;

Node* createNode(int data, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->vertices = vertices;
    newGraph->adjList = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->nodes = (PQNode*)malloc(capacity * sizeof(PQNode));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(PQNode *n1, PQNode *n2){
    PQNode temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void push(PriorityQueue* pq, int weight, int vertex) {
    pq->nodes[pq->size].vertex = vertex;
    pq->nodes[pq->size].weight = weight;
    int i = pq->size++;
    
    while (i > 0 && pq->nodes[i].weight < pq->nodes[(i - 1) / 2].weight) {
        swap(&pq->nodes[i], &pq->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

PQNode pop(PriorityQueue* pq) {
    PQNode root = pq->nodes[0];
    pq->nodes[0] = pq->nodes[--pq->size];
    int i = 0;
    
    while ((i * 2 + 1) < pq->size) {
        int smallest = i;
        
        if (pq->nodes[i * 2 + 1].weight < pq->nodes[smallest].weight) {
            smallest = i * 2 + 1;
        }
        
        if ((i * 2 + 2) < pq->size && pq->nodes[i * 2 + 2].weight < pq->nodes[smallest].weight) {
            smallest = i * 2 + 2;
        }
        
        if (smallest != i) {
            swap(&pq->nodes[i], &pq->nodes[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
    
    return root;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int primMST(Graph* graph) {
    int *visited = (int*)calloc(graph->vertices, sizeof(int));
    int *parent = (int *)malloc(sizeof(int) * graph->vertices);
    int *minEdge = (int*)malloc(graph->vertices * sizeof(int));

    for (int i = 0; i < graph->vertices; i++){
        minEdge[i] = INF;
    }
        
    PriorityQueue* pq = createPriorityQueue(graph->vertices * graph->vertices);
    int mstWeightSum = 0;

    for(int i = 0; i < graph->vertices; i++) {
        parent[i] = -1;
    }

    push(pq, 0, 0);  // Starting from vertex 0 with weight 0
    minEdge[0] = 0;
    
    while (!isEmpty(pq)) {
        PQNode current = pop(pq);
        int vertex = current.vertex;
        
        if (visited[vertex]) {
            continue;
        }

        mstWeightSum += current.weight;
        visited[vertex] = 1;
        
        Node* temp = graph->adjList[vertex];
        
        while (temp) {
            int adjVertex = temp->data;
            int adjWeight = temp->weight;

            if (!visited[adjVertex] && adjWeight < minEdge[adjVertex]) {
                minEdge[adjVertex] = adjWeight;
                push(pq, adjWeight, adjVertex);
                parent[adjVertex] = vertex;
            }

            temp = temp->next;
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    
    for (int i = 1; i < graph->vertices; i++) {
        if (parent[i] != -1) {
            printf("Edge: %d - %d, Weight: %d\n", parent[i], i, minEdge[i]);
        }
    }

    printf("Total weight of MST: %d\n", mstWeightSum);
    
    free(visited);
    free(minEdge);
    free(pq->nodes);
    free(pq);
    return mstWeightSum;
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 4, 6);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 2, 3, 1);
    // addEdge(graph, 1, 4, 2);
    // addEdge(graph, 3, 4, 1);
    // addEdge(graph, 2, 4, 2);
    
    int mstWeight = primMST(graph);
    printf("The sum of all the edge weights in the MST: %d\n", mstWeight);
    
    for (int i = 0; i < vertices; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    
    free(graph->adjList);
    free(graph);
    
    return 0;
}
