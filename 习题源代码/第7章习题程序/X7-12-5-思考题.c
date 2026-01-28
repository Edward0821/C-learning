#include <stdio.h>
#include <math.h>
/*
思考题：请用这个函数来编写一个程序判断并打印出1到1000之间所有的完美数，
请同时打印出每一个完美数的全部因子以验证这个数确实是一个完美数。
感兴趣的读者还可以修改程序，通过判断大于1000的数是否是完美数来挑战您的计算机的计算能力。
*/
int IsPrime(int x);
int IsPerfect(int x);
int main(void)
{
    int m, i, isFirstFactor = 1;
    int needNewline = 0;
    for (m=1; m<=1000; m++)
    {
        if (IsPerfect(m))
        {
            if (needNewline == 1)
            {
                printf("\n");
            }
            printf("%d is a perfect number\n", m);
            printf("The factors are: ");
            for (i=2; i<m; i++)
            {
                if (m%i == 0)
                {
                    if (isFirstFactor == 0)
                    {
                        printf(",");
                    }
                    printf("%d", i);
                    isFirstFactor = 0;
                }
            }
            isFirstFactor = 1;
            needNewline = 1;
        }
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
/* 函数功能：判断完全数，若函数返回0，则代表不是完全数，若返回1，则代表是完全数 */
int IsPerfect(int x)
{
    int i;
    int total = 0;
    for (i=1; i<x; i++)
    {
        if (x%i == 0)
        {
            total = total + i;
        }
    }
    if (total == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
