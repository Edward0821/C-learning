#include <stdio.h>
#include <math.h>
int IsPrime(int x);
int main(void)
{
    int m, n, sum = 0;
    printf("Input n:");
    scanf("%d", &n);
    for (m=1; m<=n; m++)
    {
        if (IsPrime(m))   /* 素数判定 */
        {
            sum += m;
        }
    }
    printf("sum = %d\n", sum);
    return 0;
}
/* 函数功能：判断x是否是素数，若函数返回0，则表示不是素数，若返回1，则代表是素数 */
int IsPrime(int x)
{
    int i, flag = 1;
    int squareRoot = (int)sqrt(x);
    if (x <= 1)   flag = 0;     /* 负数、0和1都不是素数 */
    for (i=2; i<=squareRoot && flag; i++)
    {
        if (x%i == 0) flag = 0; /* 若能被整除，则不是素数 */
	}
    return flag;
}
