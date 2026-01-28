#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Calculate(int x, char op, int y);
int CreateRandomNumber(void);
int main(void)
{
	int a, b, answer, wrongTimes = 0, flag = 0;
	srand(time(NULL));
	a = CreateRandomNumber();
	b = CreateRandomNumber();
	do{
		printf("%d * %d = ?\n", a, b);
		scanf("%d", &answer);
		if (answer == Calculate(a, '*', b))
		{
			printf("Right!\n");
			flag = 1;                       /* 做对，则将标志变量置为真 */
		}
		else
		{
			wrongTimes++;
			if (wrongTimes < 3)
				printf("Wrong! Please try again.\n");
			else
				printf("Wrong! You have tried three times! Test over!");
		}
	}while (flag != 1 && wrongTimes < 3);/* 未做对且未超过3次时继续循环 */
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
