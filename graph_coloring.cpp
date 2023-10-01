#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int numVertices, numColors;

// Function to check if it's safe to color a vertex with a given color
bool isSafe(int v, int c) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to assign colors to vertices
bool graphColoringUtil(int v) {
    if (v == numVertices) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= numColors; c++) {
        if (isSafe(v, c)) {
            colors[v] = c;

            if (graphColoringUtil(v + 1)) {
                return true; // Recur for the next vertex
            }

            colors[v] = 0; // Backtrack if no color works
        }
    }

    return false; // If no color can be assigned to this vertex
}

// Function to solve the Graph Coloring Problem
void graphColoring() {
    if (!graphColoringUtil(0)) {
        printf("No solution exists.\n");
    } else {
        printf("Vertex colors:\n");
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d -> Color %d\n", i + 1, colors[i]);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    graphColoring();

    return 0;
}
