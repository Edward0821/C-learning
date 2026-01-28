#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Calculate(int x, char op, int y);
int CreateRandomNumber(void);
int main(void)
{
	int a, b, answer, i, rightNumber = 0;
	srand(time(NULL));
	for (i=0; i<10; i++)
	{
		a = CreateRandomNumber();
		b = CreateRandomNumber();
		printf("%d * %d = ?\n", a, b);
		scanf("%d", &answer);
		if (answer == Calculate(a, '*', b))
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
