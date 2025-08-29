#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // maximum number of vertices

int graph[MAX][MAX];  // adjacency matrix
int visited[MAX];
int n; // number of vertices

// DFS function
void DFS(int vertex) {
    printf("%d ", vertex);  // print the visited vertex
    visited[vertex] = 1;    // mark as visited

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);  // recursive DFS call
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  // edge from u to v
        graph[v][u] = 1;  // for undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}

