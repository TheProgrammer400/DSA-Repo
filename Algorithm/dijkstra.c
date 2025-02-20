#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    int weight;
    struct Node *next;
} Node;

typedef struct Graph {
    int vertices;
    Node **adjList;
} Graph;

Node *createNode(int data, int weight) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
}

Graph *createGraph(int vertices) {
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertices = vertices;
    newGraph->adjList = (Node **)malloc(vertices * sizeof(Node *));

    for (int i = 0; i < vertices; i++) {
        newGraph->adjList[i] = NULL;
    }

    return newGraph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

int minDistance(int dist[], int visited[], int vertices){
    int min = INT_MAX, minIndex = -1;

    for(int i=0; i<vertices; i++){
        if (!visited[i] && dist[i] <= min){
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(Graph *graph, int src) {
    int vertices = graph->vertices;
    int dist[vertices];
    int visited[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);

        if (u == -1){
            break;
        }

        visited[u] = 1;

        Node *temp = graph->adjList[u];

        while (temp) {
            int v = temp->data;
            int weight = temp->weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }

            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");

    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int vertices = 5;
    Graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 0, 7);

    // for(int i=0; i<vertices; i++){
    //     for(int j=0; j<vertices; j++){
    //         int num;
    //         scanf("%d", &num);

    //         if (num == 0 || j<= i){
    //             continue;
    //         }

    //         addEdge(graph, i, j, num);
    //     }
    // }

    int src = 0;
    dijkstra(graph, src);

    return 0;
}
