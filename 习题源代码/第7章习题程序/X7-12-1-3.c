#include <stdio.h>
int IsPrime(int x);
int main(void)
{
    int m;
    printf("Input m:");
    scanf("%d", &m);
    if (IsPrime(m))   /* 素数判定 */
        printf("%d is a prime number\n", m);
    else
        printf("%d is not a prime number\n", m);
    return 0;
}
/* 函数功能：判断x是否是素数，若函数返回0，则表示不是素数，若返回1，则代表是素数 */
int IsPrime(int x)
{
    int i;
    if (x <= 1)  return 0;      /* 负数、0和1都不是素数 */
    for (i=2; i<=x-1; i++)
    {
        if (x%i == 0) return 0; /* 若能被整除，则不是素数 */
    }
    return 1;
}
