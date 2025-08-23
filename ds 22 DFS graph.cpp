#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

// DFS function
void DFS(int graph[][MAX], int n, int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            DFS(graph, n, i);
        }
    }
}

// Main function
int main() {
    int n, e, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) format (0-indexed vertices):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(graph, n, start);
    printf("\n");

    return 0;
}

