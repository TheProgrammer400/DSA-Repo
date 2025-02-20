#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct Graph{
    int vertices;
    Node **adjList;
} Graph;

typedef struct Queue{
    int size;
    int *arr;
    int start;
    int end;
    int currSize;
} Queue;

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Graph *createGraph(int vertices){
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertices = vertices;
    newGraph->adjList = (Node **)malloc(vertices * sizeof(Node *));

    for(int i=0; i<vertices; i++){
        newGraph->adjList[i] = NULL;
    }

    return newGraph;
}

void addEdge(Graph *graph, int src, int dest){
    Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void init(Queue *q1){
    q1->size = 20;
    q1->arr = (int *)malloc(sizeof(int) * q1->size);
    q1->currSize = 0;
    q1->start = q1->end = -1;
}

void enqueue(Queue *q1, int data){
    if (q1->currSize == q1->size){
        printf("The queue is full!");
        return ;
    }

    if (q1->currSize == 0){
        q1->start = q1->end = 0;
    } else {
        q1->end = (q1->end+1) % q1->size;
    }

    q1->arr[q1->end] = data;
    q1->currSize++;
}

int dequeue(Queue *q1){
    if (q1->currSize == 0){
        printf("The queue is empty!\n");
        return -1;
    }

    int popped = q1->arr[q1->start];

    if (q1->start == q1->end){
        q1->start = q1->end = -1;
    } else {
        q1->start = (q1->start+1) % q1->size;
    }

    q1->currSize--;
    return popped;
}

int isEmpty(Queue *q1){
    return q1->currSize == 0;
}

void BFS(Graph *graph, int startVertex){
    int *visited = (int *)malloc(graph->vertices * sizeof(int));

    for(int i=0; i<graph->vertices; i++){
        visited[i] = 0;
    }

    Queue q1;
    init(&q1);

    visited[startVertex] = 1;
    enqueue(&q1, startVertex);

    while (!isEmpty(&q1)){
        int currentVertex = dequeue(&q1);
        printf("%d ", currentVertex);

        Node *temp = graph->adjList[currentVertex];

        while (temp){
            int adjVertex = temp->data;

            if (!visited[adjVertex]){
                visited[adjVertex] = 1;
                enqueue(&q1, adjVertex);
            }

            temp = temp->next;
        }
    }

    free(visited);
}

int main(){
    int vertices = 5;

    Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    BFS(graph, 0);

    return 0;
}