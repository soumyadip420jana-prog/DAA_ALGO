#include <stdio.h>

void insertionSort(int a[], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = temp;
    }
}

int main() {
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(a) / sizeof(a[0]);

    insertionSort(a, n);

    printf("Ascending Order:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nDescending Order:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);

    printf("\n\nTime Complexity:\n");
    printf("Best Case    : O(n)\n");
    printf("Average Case : O(n^2)\n");
    printf("Worst Case   : O(n^2)\n");

    printf("\nSpace Complexity : O(1)\n");

    return 0;
}