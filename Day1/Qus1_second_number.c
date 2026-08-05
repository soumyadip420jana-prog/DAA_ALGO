#include<stdio.h>
void  findSecond(int arr[], int n)
{
    int secondSmallest=-1;
    int secondLargest=-1;
    int i;

    //  smallest
   
    for (i = 1; i < n; i++)
    {
        if (arr[i] != arr[0])
        {
            secondSmallest = arr[i];
            break;
        }
    }

    // largest
   
    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] != arr[n - 1])
        {
            secondLargest = arr[i];
            break;
        }
    }

    printf("Second Smallest = %d\n", secondSmallest);
    printf("Second Largest = %d\n", secondLargest);
}
int main()
{
    int arr[] = {1, 1, 2, 3, 4, 5,6};   
    int n = sizeof(arr) / sizeof(arr[0]);

    findSecond(arr, n);

    return 0;
}