#include <stdio.h>
#include <time.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n, m;
    clock_t st, end;
    double time;

    printf("Enter the two numbers: ");
    scanf("%d%d", &n, &m);

    st = clock();   

    printf("The GCD of %d and %d is %d\n", n, m, gcd(n, m));

    end = clock();  

    time = (double)(end - st) / CLOCKS_PER_SEC;

    printf("Execution time = %f seconds\n", time);

    return 0;
}