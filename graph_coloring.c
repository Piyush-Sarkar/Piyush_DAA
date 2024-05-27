#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to print the colors assigned to vertices
void printSolution(int colors[], int V) {
    printf("Vertex   Color\n");
    for (int i = 0; i < V; i++)
        printf("%d         %d\n", i, colors[i]);
}

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, bool graph[MAX][MAX], int colors[], int c, int V) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == colors[i])
            return false;
    return true;
}

// A utility function to solve the graph coloring problem
bool graphColoringUtil(bool graph[MAX][MAX], int m, int colors[], int v, int V) {
    // If all vertices are assigned a color then return true
    if (v == V)
        return true;

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is fine
        if (isSafe(v, graph, colors, c, V)) {
            colors[v] = c;

            // Recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, colors, v + 1, V))
                return true;

            // If assigning color c doesn't lead to a solution then remove it
            colors[v] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return false;
}

// This function solves the graph coloring problem using backtracking
bool graphColoring(bool graph[MAX][MAX], int m, int V) {
    int colors[V];
    for (int i = 0; i < V; i++)
        colors[i] = 0;

    // Call graphColoringUtil() for vertex 0
    if (!graphColoringUtil(graph, m, colors, 0, V)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(colors, V);
    return true;
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    bool graph[MAX][MAX] = { false };

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int edge;
            scanf("%d", &edge);
            graph[i][j] = edge ? true : false;
        }
    }

    int m;
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    return 0;
}
