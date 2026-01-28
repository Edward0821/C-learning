#include <stdio.h>
#include <math.h>
int IsPerfect(int x);
int main(void)
{
    int m;
    printf("Input m:");
    scanf("%d", &m);
    if (IsPerfect(m))  /* 完全数判定 */
        printf("%d is a perfect number\n", m);
    else
        printf("%d is not a perfect number\n", m);
    return 0;
}
/* 函数功能：判断完全数，若函数返回0，则代表不是完全数，若返回1，则代表是完全数 */
int IsPerfect(int x)
{
    int i;
    int total = 0;          /* 1没有真因子，不是完全数 */
    for (i=1; i<x; i++)
    {
        if (x%i == 0)
            total = total + i;
    }
    return total==x ? 1 : 0;
}
