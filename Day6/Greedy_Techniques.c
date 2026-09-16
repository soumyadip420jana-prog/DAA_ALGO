#include <stdio.h>

#define INF 9999

int main() {
    int n, start;
    int cost[20][20];
    int visited[20] = {0};
    int mst[20][20] = {0};
    int totalCost = 0;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);

    // Read adjacency matrix from file
    FILE *fp = fopen("inUnAdjMat.dat", "r");

    if (fp == NULL) {
        printf("File cannot be opened!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &cost[i][j]);

            // 0 means there is no edge
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    fclose(fp);

    // Convert vertex number to array index
    start--;

    visited[start] = 1;

    printf("\nMinimum Spanning Tree Edges:\n");

    // MST contains n-1 edges
    for (int edge = 0; edge < n - 1; edge++) {

        int min = INF;
        int u = -1;
        int v = -1;

        // Find minimum edge
        for (int i = 0; i < n; i++) {
            if (visited[i]) {

                for (int j = 0; j < n; j++) {

                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Add edge to MST
        visited[v] = 1;

        mst[u][v] = min;
        mst[v][u] = min;

        totalCost += min;

        printf("%d -> %d = %d\n", u + 1, v + 1, min);
    }

    // Display MST adjacency matrix
    printf("\nCost Adjacency Matrix of MST:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", mst[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", totalCost);

    return 0;
}
