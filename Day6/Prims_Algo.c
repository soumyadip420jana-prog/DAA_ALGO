#include <stdio.h>

#define INF 9999

int main() {
    int n, a[10][10], visited[10] = {0};
    int i, j, edges = 0, cost = 0;
    int min, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                a[i][j] = INF;
        }

    visited[0] = 1;

    printf("\nMST Edges:\n");

    while (edges < n - 1) {
        min = INF;

        for (i = 0; i < n; i++)
            if (visited[i])
                for (j = 0; j < n; j++)
                    if (!visited[j] && a[i][j] < min) {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }

        printf("%d - %d = %d\n", u + 1, v + 1, min);

        cost += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}