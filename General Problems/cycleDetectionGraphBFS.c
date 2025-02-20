#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

typedef struct Queue {
    int items[100];
    int front, rear;
} Queue;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == -1) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

int bfsCycleCheck(Graph* graph, int startVertex, int visited[], int *cycleLength) {
    int parent[graph->numVertices];

    for (int i = 0; i < graph->numVertices; i++) {
        parent[i] = -1;
    }

    Queue* q = createQueue();
    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        Node* temp = graph->adjLists[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                parent[adjVertex] = currentVertex;
                enqueue(q, adjVertex);
            } else if (adjVertex != parent[currentVertex]) {
                // cycle detected

                int length = 1;
                int tracer = currentVertex;

                while (tracer != adjVertex){
                    length++;
                    tracer = parent[tracer];
                }

                *cycleLength = length;
                return 1;
            }

            temp = temp->next;
        }
    }

    return 0;
}

int hasCycle(Graph* graph) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            int length = 0;
            if (bfsCycleCheck(graph, i, visited, &length)) {
                free(visited);
                return length;
            }
        }
    }

    free(visited);
    return 0;
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 4);

    if (hasCycle(graph))
        printf("Graph contains a cycle.\n");
    else
        printf("Graph does not contain a cycle.\n");

    return 0;
}
