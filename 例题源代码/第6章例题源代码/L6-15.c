#include <stdio.h>
#include <math.h>
int main(void)
{
    int i, a, n;
    long long sum;
    printf("Input a,n:");
    scanf("%d,%d", &a, &n);
    sum = 0;
    for (i=1; i<=n; i++)
    {
        sum = sum + pow(a,i);        
    }
    printf("sum=%I64d\n", sum);
    return 0;
}

