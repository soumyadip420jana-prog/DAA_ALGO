#include <stdio.h>

#define INF 999999

int main() {
    int n, i, j, k;
    int p[20];
    int m[20][20];
    int s[20][20];

  
    printf("Enter number of matrices: ");
    scanf("%d", &n);

   
    printf("Enter dimensions:\n");

    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    // Initially cost is 0
    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    // Find minimum cost
    for (int length = 2; length <= n; length++) {

        for (i = 1; i <= n - length + 1; i++) {

            j = i + length - 1;

            m[i][j] = INF;

            //  split
            for (k = i; k < j; k++) {

                int cost = m[i][k]
                         + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print M table
    printf("\nM Table:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j < i)
                printf("0\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    // Print S table
    printf("\nS Table:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j <= i)
                printf("0\t");
            else
                printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum scalar multiplications = %d\n",
           m[1][n]);

    return 0;
}