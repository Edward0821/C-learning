/*
键盘任意输入一个整数m，若m不是素数，
则对m进行质因数分解，并将m表示为质因数从小到大顺序排列的乘积形式输出，
否则输出"It is a prime number\n"。
例如，用户输入90时，程序输出90 = 2 * 3 * 3 * 5；用户输入91时，
程序输出"It is a prime number\n"。
*/
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
/* 函数功能：输出x的质因数连乘 */
void OutputPrimeFactor(int x)
{
    int i;
    for (i=2; i<x; i++)
    {
        if (x%i == 0)
        {
            printf("%d * ", i);
            OutputPrimeFactor(x/i); /* 递归调用该函数 */
            return;                 /* 不可以使用break */
        }
    }
    printf("%d", i);                /* 输出最后一个因子（质因数，不能再分解）*/
}
