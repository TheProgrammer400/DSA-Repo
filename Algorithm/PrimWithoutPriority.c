#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

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
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjList = (Node **)malloc(vertices * sizeof(Node *));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

int minDistance(int dist[], int visited[], int vertices) {
    int min = INF, minIndex = -1;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void prim(Graph *graph) {
    int vertices = graph->vertices;
    int dist[vertices];
    int visited[vertices];
    int parent[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[0] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);
        visited[u] = 1;

        Node *temp = graph->adjList[u];
        
        while (temp) {
            int v = temp->data;
            int weight = temp->weight;

            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                parent[v] = u;
            }

            temp = temp->next;
        }
    }

    // Calculate and print minimum cost
    int minimumCost = 0;

    for (int i = 1; i < vertices; i++) {
        if (parent[i] != -1) {
            printf("%d - %d (Weight: %d)\n", parent[i], i, dist[i]);
            minimumCost += dist[i];
        }
    }
    
    printf("Minimum Cost of MST: %d\n", minimumCost);
}

int main() {
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    Graph *graph = createGraph(vertices);

    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    prim(graph);
    return 0;
}
