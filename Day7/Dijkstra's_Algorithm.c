#include <stdio.h>

#define INF 9999

int main() {
    int n, graph[10][10];
    int dist[10], visited[10] = {0};
    int source, i, j, min, u;

    // Number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input graph
    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            // 0 means no edge
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    // Source vertex
    printf("Enter source vertex: ");
    scanf("%d", &source);

    source--;

    // Initially all distances are INF
    for (i = 0; i < n; i++)
        dist[i] = INF;

    // Source distance is 0
    dist[source] = 0;

    // Dijkstra
    for (i = 0; i < n; i++) {

        min = INF;
        u = -1;

        // Find smallest distance
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        // Mark as visited
        visited[u] = 1;

        // Update distances
        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                dist[u] + graph[u][j] < dist[j]) {

                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // Print result
    printf("\nShortest Distance:\n");

    for (i = 0; i < n; i++)
        printf("%d -> %d = %d\n",
               source + 1, i + 1, dist[i]);

    return 0;
}