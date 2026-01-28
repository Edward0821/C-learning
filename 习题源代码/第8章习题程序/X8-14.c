#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void MakeDigit(int a[]);
int InputGuess(int b[]);
int IsRightPosition(int magic[], int guess[]);
int IsRightDigit(int magic[], int guess[]);
int main(void)
{
	int a[10];				/* 记录计算机所想的数 */
	int b[4];				/* 记录人猜的数 */
   	int count;				/* 记录已经猜的次数 */
	int rightDigit;			/* 猜对的数字个数 */
	int rightPosition;		/* 数字和位置都猜对的个数 */
	int level;				/* 最多允许猜的次数 */
    srand(time(NULL));
	MakeDigit(a);       		/* 随机生成一个各位相异的4位数 */
	printf("How many times do you want to guess?");
	scanf("%d", &level);
	count = 0;
	do{
		printf("No.%d of %d times:\n", count+1, level);
		printf("Please input a number:");
		if (InputGuess(b) != 0) /* 读入用户的猜测 */
		{
			count++;
			rightPosition = IsRightPosition(a, b);/*数字和位置都猜对的个数*/
			rightDigit = IsRightDigit(a, b);   /*用户猜对的数字个数*/
			rightDigit = rightDigit - rightPosition;
			printf("%dA%dB\n", rightPosition, rightDigit);
		}
	}while (count < level && rightPosition != 4);
	if (rightPosition == 4)
		printf("Congratulations, you got it at No.%d\n", count);
	else
		printf("Sorry, you haven't got it, see you next time!\n");
	printf("Correct answer is:%d%d%d%d\n", a[0], a[1], a[2], a[3]);
	return 0;
}
/* 	函数功能： 随机生成一个各位相异的4位数 */
void MakeDigit(int a[])
{
	int j, k, temp;
    for (j=0; j<10; j++)
	{
		a[j] = j;
	}
	for (j=0; j<10; j++)
	{
		k = rand() % 10;
		temp = a[j];
		a[j]  = a[k];
		a[k] = temp;
	}
}
/*	函数功能： 读用户猜的数，读入失败返回0，否则非0 */
int InputGuess(int b[])
{
	int i, ret = 1;
	for (i=0; i<4; i++)
	{
		ret = scanf("%1d", &b[i]);
		if (ret != 1) 		   	         /* 如果输入非法 */
		{
			printf("Input Data Type Error!\n");
			while (getchar() != '\n'); /* 清除输入缓冲区中的内容 */
			return 0;
		}
	}
	if (b[0] == b[1] || b[0] == b[2] || b[0] == b[3] ||
		b[1] == b[2] || b[1] == b[3] || b[2] == b[3])
	{
		printf("The digits must be different from each other!\n");
		return 0;
	}
	else
	{
		return 1;
	}
}
/* 	函数功能： 统计guess和magic数字和位置都一致的个数 */
int IsRightPosition(int magic[],int guess[])
{
	int	rightPosition = 0;
	int j;
	for (j=0; j<4; j++)
	{
		if (guess[j] == magic[j])
			rightPosition = rightPosition + 1;
	}
	return rightPosition;
}
/* 	函数功能：统计guess和magic数字一致（不管位置是否一致）的个数 */
int IsRightDigit(int magic[],int guess[])
{
	int	rightDigit = 0;
	int j, k;
	for (j=0; j<4; j++)
	{
		for (k=0; k<4; k++)
		{
			if (guess[j] == magic[k])
				rightDigit = rightDigit + 1;
		}
	}
	return rightDigit;
}
