#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[100];

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, n - 1);

    printf("Ascending Order:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nDescending Order:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);

    printf("\n\nTime Complexity:\n");
    printf("Best Case    : O(n log n)\n");
    printf("Average Case : O(n log n)\n");
    printf("Worst Case   : O(n log n)\n");

    printf("\nSpace Complexity : O(n)\n");

    return 0;
}