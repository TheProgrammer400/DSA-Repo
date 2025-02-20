#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int visited[], int n, int stack[], int *top) {
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(graph, i, visited, n, stack, top);
        }
    }

    stack[++(*top)] = vertex;
}

void DFSUtil(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int visited[], int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFSUtil(graph, i, visited, n);
        }
    }
}

void transposeGraph(int graph[MAX_VERTICES][MAX_VERTICES], int transposed[MAX_VERTICES][MAX_VERTICES], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposed[i][j] = graph[j][i];
        }
    }
}

void findSCCs(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES], top = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, n, stack, &top);
        }
    }

    int transposed[MAX_VERTICES][MAX_VERTICES] = {0};
    transposeGraph(graph, transposed, n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Strongly Connected Components:\n");
    while (top != -1) {
        int vertex = stack[top--];

        if (!visited[vertex]) {
            DFSUtil(transposed, vertex, visited, n);
            printf("\n");
        }
    }
}
int main() {
    int n, edges, src, dest;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
    }

    findSCCs(graph, n);
    return 0;
}