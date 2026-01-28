#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Calculate(int x, char op, int y);
int CreateRandomNumber(void);
int main(void)
{
    int a, b, answer;
    int isFirstTime = 1;
    srand(time(NULL));
    a = CreateRandomNumber();
    b = CreateRandomNumber();
    do{
        if (isFirstTime == 0)
            printf("Wrong! Please try again.\n");
        printf("%d * %d = ?\n", a, b);
        scanf("%d", &answer);
        isFirstTime = 0;
    }while (answer != Calculate(a, '*', b));
    printf("Right!\n");
    return 0;
}
/* 函数功能：计算两个数（x，y）的四则运算（由op定），返回计算结果值 */
int Calculate(int x, char op, int y)
{
    switch(op)
    {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        default:  printf("Operator error!\n"); return 0;
    }
}
/* 函数功能：生成一个1~10的随机整数 */
int CreateRandomNumber(void)
{
    return rand() % 10 + 1;
}
