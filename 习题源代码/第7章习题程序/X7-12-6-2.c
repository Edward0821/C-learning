#include <stdio.h>
#include <math.h>
int IsPrime(int x);
void OutputPrimeFactor(int x);
int main(void)
{
    int m;
    printf("Input m:");
    scanf("%d", &m);
    if (IsPrime(m))
    {
        printf("It is a prime number\n");
    }
    else
    {
        printf("%d = ", m);
        OutputPrimeFactor(m);
    }
    return 0;
}
/* 函数功能：判断x是否是素数，若函数返回0，则表示不是素数，若返回1，则代表是素数 */
int IsPrime(int x)
{
    int i, flag = 1;
    int squareRoot = sqrt(x);
    if (x <= 1)        /* 负数、0和1都不是素数 */
    {
        flag = 0;
    }
    for (i=2; i<=squareRoot && flag; i++)
    {
        if (x%i == 0)  /* 若能被整除，则不是素数 */
        {
            flag = 0;
        }
    }
    return flag;
}
void OutputPrimeFactor(int x)
{
    int i;
    if (!IsPrime(x))
    {
        for (i=2; i<x; i++)
        {
            if (x%i == 0)
            {
                printf("%d * ", i);
                OutputPrimeFactor(x/i); /* 递归调用该函数 */
                return;                    /* 也可以使用break */
            }
        }
    }
    else                              /* 输出最后一个因子（质因数，不能再分解）*/
    {
        printf("%d", x);
    }
}
