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

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    return newNode;
}

Graph *createGraph(int vertices){
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjList = (Node **)malloc(vertices * sizeof(Node *));

    for(int i=0; i<vertices; i++){
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest){
    Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void DFSHelper(Graph *graph, int vertex, int *visited){
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node *temp = graph->adjList[vertex];

    while (temp){
        int adjVertex = temp->data;

        if (!visited[adjVertex]){
            DFSHelper(graph, adjVertex, visited);
        }

        temp = temp->next;
    }
}

void DFS(Graph *graph, int startVertex){
    int *visited = (int *)malloc(sizeof(int) * graph->vertices);

    for(int i=0; i<graph->vertices; i++){
        visited[i] = 0;
    }
    
    DFSHelper(graph, startVertex, visited);
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

    DFS(graph, 0);

    return 0;
}