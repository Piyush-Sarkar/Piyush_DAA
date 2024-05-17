#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 99

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to print the solution
void printArr(int dist[], int n) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        if (dist[i] == INF)
            printf("%d \t\t %s\n", i, "INF");
        else
            printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src to all other vertices
void BellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[V];

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: check for negative-weight cycles.
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printArr(dist, V);
}

int main() {
    int V, E = 0, src;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int adjMatrix[V][V];

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adjMatrix[i][j]);
            if (adjMatrix[i][j] != INF && adjMatrix[i][j] != 0) {
                E++;
            }
        }
    }

    struct Edge edges[E];
    int k = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adjMatrix[i][j] != INF && adjMatrix[i][j] != 0) {
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = adjMatrix[i][j];
                k++;
            }
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    BellmanFord(edges, V, E, src);

    return 0;
}
