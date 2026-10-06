#include <stdio.h>

struct Edge {
    int u, v, w;
};

int find(int p[], int x) {
    while (p[x] != x)
        x = p[x];

    return x;
}

int main() {
    int n, e, i, j, cost = 0, count = 0;
    struct Edge a[20], temp;
    int parent[10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < e; i++)
        scanf("%d %d %d",
              &a[i].u, &a[i].v, &a[i].w);

    // Sort edges
    for (i = 0; i < e - 1; i++)
        for (j = i + 1; j < e; j++)
            if (a[i].w > a[j].w) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    // Initially separate sets
    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nMST Edges:\n");

    for (i = 0; i < e && count < n - 1; i++) {

        int u = find(parent, a[i].u);
        int v = find(parent, a[i].v);

        if (u != v) {
            printf("%d - %d = %d\n",
                   a[i].u, a[i].v, a[i].w);

            cost += a[i].w;
            parent[u] = v;
            count++;
        }
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}