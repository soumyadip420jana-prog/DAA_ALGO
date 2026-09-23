#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char s1[100], s2[100];
    int dp[100][100];
    int i, j;

    printf("Enter the first string into an array: ");
    scanf("%s", s1);

    printf("Enter the second string into an array: ");
    scanf("%s", s2);

    int n = strlen(s1);
    int m = strlen(s2);

    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {

            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    
    int length = dp[n][m];
    char lcs[100];

    lcs[length] = '\0';

    i = n;
    j = m;

    while (i > 0 && j > 0) {

        if (s1[i - 1] == s2[j - 1]) {
            lcs[length - 1] = s1[i - 1];
            i--;
            j--;
            length--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    printf("\nLCS: %s", lcs);
    printf("\nLCS Length: %d\n", dp[n][m]);

    return 0;
}
