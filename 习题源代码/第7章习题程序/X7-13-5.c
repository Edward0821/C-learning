#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Calculate(int x, char op, int y);
int CreateRandomNumber(void);
char CreateRandomOperator(void);
int main(void)
{
    int  a, b, userAnswer, i, rightNumber,  flag;
    char opChar;
    srand(time(NULL));
    do
    {
        rightNumber = flag = 0;
        for (i=0; i<10; i++)
        {
            a = CreateRandomNumber();
            b = CreateRandomNumber();
            opChar = CreateRandomOperator();
            printf("%d %c %d = ?\n", a, opChar, b);
            scanf("%d", &userAnswer);
            if (userAnswer == Calculate(a, opChar, b))
            {
                printf("Right!\n");
                rightNumber++;
            }
            else
            {
                printf("Wrong!\n");
            }
        }
        printf("Total score is %d\n", rightNumber*10);
        printf("Rate of correctness is %d%%\n", rightNumber*10);
        if (rightNumber*10 < 75)
        {
            printf("Once Again!\n");
            rightNumber = 0;
            flag = 1;
        }
    }
    while (flag);
    return 0;
}
/* 函数功能：计算两个数（x，y）的四则运算（由op定），返回计算结果值 */
int Calculate(int x, char op, int y)
{
    switch(op)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        printf("Operator error!\n");
        return 0;
    }
}
/* 函数功能：生成一个1~10的随机整数 */
int CreateRandomNumber(void)
{
    return rand() % 10 + 1;
}
/* 函数功能：随机生成一个运算符号（+,-,*,/）*/
char CreateRandomOperator(void)
{
    int op;
    op = rand() % 4 + 1;
    switch (op)
    {
    case 1:
        return '+';
    case 2:
        return '-';
    case 3:
        return '*';
    case 4:
        return '/';
    }
    return 0;
}
