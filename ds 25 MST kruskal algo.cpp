#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge edges[MAX];
};

// Function to find set of an element i (with path compression)
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Function to union two sets
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's Algorithm
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[MAX];
    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges

    // Sort all edges in increasing order
    qsort(graph->edges, graph->E, sizeof(struct Edge), compare);

    int parent[MAX], rank[MAX];

    for (int v = 0; v < V; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];

        int x = find(parent, next_edge.u);
        int y = find(parent, next_edge.v);

        if (x != y) {
            result[e++] = next_edge;
            unionSets(parent, rank, x, y);
        }
    }

    printf("Edges in Minimum Spanning Tree (Kruskal's Algorithm):\n");
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].u, result[i].v, result[i].weight);
}

// Main function
int main() {
    struct Graph graph;
    int u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &graph.V);

    printf("Enter number of edges: ");
    scanf("%d", &graph.E);

    printf("Enter edges (u v weight) format (0-indexed vertices):\n");
    for (int i = 0; i < graph.E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph.edges[i].u = u;
        graph.edges[i].v = v;
        graph.edges[i].weight = w;
    }

    kruskalMST(&graph);

    return 0;
}

