#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Calculate(int x, char op, int y);
int CreateRandomNumber(void);
char CreateRandomOperator(void);
void PrintRandomRightEvaluation(void);
void PrintRandomWrongEvaluation(void);
int main(void)
{
	int  a, b, userAnswer, i, rightNumber, flag;
	char opChar;
	srand(time(NULL));
	do{
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
				PrintRandomRightEvaluation();
				rightNumber++;
			}
			else
			{
				PrintRandomWrongEvaluation();
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
	}while (flag);
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
/* 函数功能：随机生成一个运算符号（+,-,*,/）*/
char CreateRandomOperator(void)
{
    int op;
    op = rand() % 4 + 1;
    switch (op)
    {
	case 1: return '+';
	case 2: return '-';
	case 3: return '*';
	case 4: return '/';
	}
	return 0;
}
/* 函数功能：生成一个题目做对的随机提示 */
void PrintRandomRightEvaluation(void)
{
    int i;
    i = rand() % 4 + 1;
    switch(i)
    {
	case 1: printf("Very good!\n");
		break;
	case 2: printf("Excellent!\n");
		break;
	case 3: printf("Nice work!\n");
		break;
	case 4: printf("Keep up the good work!\n");
		break;
	default:printf("Wrong type!");
    }
}
/* 函数功能：生成一个题目做错的随机提示 */
void PrintRandomWrongEvaluation(void)
{
    int i;
    i = rand() % 4 + 1;
    switch(i)
    {
	case 1: printf("No. Please try again.\n");
		break;
	case 2: printf("Wrong. Try once more.\n");
		break;
	case 3: printf("Don't give up!\n");
		break;
	case 4: printf("Not correct. Keep trying.\n");
		break;
	default:printf("Wrong type!");
    }
}
