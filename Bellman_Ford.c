#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

#define INF 99

// Function to print the solution
void printSolution(int dist[], int n) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; ++i)
        if (dist[i] == INF)
            printf("%d\t\t%s\n", i, "INF");
        else
            printf("%d\t\t%d\n", i, dist[i]);
}

// Function to run the Bellman-Ford algorithm
void bellmanFord(int** graph, int V, int src) {
    int dist[V];
    
    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Step 3: Check for negative-weight cycles.
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    printSolution(dist, V);
}

int main() {
    int V;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    // Allocate memory for the adjacency matrix
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    // Initialize graph with user input
    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    
    bellmanFord(graph, V, src);
    
    // Free allocated memory
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
