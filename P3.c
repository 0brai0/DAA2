#include <stdio.h>

#define V 4  // Number of vertices

void printMatrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void warshall(int graph[V][V]) {
    int dist[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
            }
        }
    }

    printf("Transitive closure matrix:\n");
    printMatrix(dist);
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix (row by row, %d rows):\n", V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    warshall(graph);

    return 0;
}
