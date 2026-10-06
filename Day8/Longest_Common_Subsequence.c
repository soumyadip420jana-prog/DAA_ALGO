#include <stdio.h>
#include <string.h>

int main() {

    char a[100], b[100];
    int dp[100][100];
    int i, j;

    // Input strings
    printf("Enter first string: ");
    scanf("%s", a);

    printf("Enter second string: ");
    scanf("%s", b);

    int m = strlen(a);
    int n = strlen(b);

    // First row and column = 0
    for (i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (j = 0; j <= n; j++)
        dp[0][j] = 0;

    // Create LCS table
    for (i = 1; i <= m; i++) {

        for (j = 1; j <= n; j++) {

            // Characters are same
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            // Characters are different
            else if (dp[i - 1][j] > dp[i][j - 1])
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    // Print LCS length
    printf("\nLCS Length = %d\n", dp[m][n]);

    // Find LCS string
    char lcs[100];
    int index = dp[m][n];

    lcs[index] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0) {

        if (a[i - 1] == b[j - 1]) {

            lcs[index - 1] = a[i - 1];

            i--;
            j--;
            index--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }

        else {
            j--;
        }
    }

    printf("LCS = %s\n", lcs);

    return 0;
}