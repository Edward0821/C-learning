#include <stdio.h>
long Fib(int n);
int main(void)
{
    for (int i=1; i<=12; i++)
    {
        printf("%4ld", Fib(i));
    }
    printf("\nTotal = %d\n", Fib(12));
    return 0;
}
//函数功能：正向顺推法计算并返回Fibonacci数列的第n项
long Fib(int n)
{
    long f1 = 1, f2 = 2, f3;
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else
    {
        for (int i=3; i<=n; i++) //每递推一次计算一项
        {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
}
