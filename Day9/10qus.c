#include <stdio.h>

#define MAX 20
#define INF 99999

int dist[MAX][MAX];
int next[MAX][MAX];

void floydWarshall(int n)
{
    int i, j, k;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printPath(int u, int v)
{
    if (next[u][v] == -1)
    {
        printf("No path");
        return;
    }

    printf("%d", u + 1);

    while (u != v)
    {
        u = next[u][v];
        printf("-->%d", u + 1);
    }
}

int main()
{
    FILE *fp;
    int n, i, j;
    int u, v;

    fp = fopen("inDiAdjMat2.dat", "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    printf("Number of Vertices: ");
    scanf("%d", &n);

    /* Read adjacency matrix */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &dist[i][j]);

            /*
               0 means no edge, except diagonal.
            */
            if (i != j && dist[i][j] == 0)
                dist[i][j] = INF;

            if (i == j)
                next[i][j] = i;
            else if (dist[i][j] != INF)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    fclose(fp);

    /* Floyd-Warshall */
    floydWarshall(n);

    /* Print shortest path matrix */
    printf("\nShortest Path Weight Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("%5s", "INF");
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n");
    }

    /* Source and destination */
    printf("\nEnter the source and destination vertex: ");
    scanf("%d %d", &u, &v);

    u--;
    v--;

    if (dist[u][v] == INF)
    {
        printf("\nNo path exists from %d to %d.\n", u + 1, v + 1);
    }
    else
    {
        printf("\nShortest Path from vertex %d to vertex %d: ",
               u + 1, v + 1);

        printPath(u, v);

        printf("\nPath weight: %d\n", dist[u][v]);
    }

    return 0;
}