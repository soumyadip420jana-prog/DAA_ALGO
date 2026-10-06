#include <stdio.h>

#define INF 9999

int main() {
    int n, a[10][10];
    int i, j, k;

    // Number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input matrix
    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);

            // 0 means no edge
            if (i != j && a[i][j] == 0)
                a[i][j] = INF;
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {

        for (i = 0; i < n; i++) {

            for (j = 0; j < n; j++) {

                // Check shorter path through k
                if (a[i][k] + a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }

    // Print shortest path matrix
    printf("\nShortest Path Matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            if (a[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", a[i][j]);
        }

        printf("\n");
    }

    return 0;
}