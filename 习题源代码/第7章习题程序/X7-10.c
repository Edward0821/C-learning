#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int Input(int t);
int ControlCompter(int s);
int Rnd(void);
int main(void)
{
	int tol = 1;                  /* 从1开始报数 */
	if (Rnd() == 1)				/* 取随机数决定计算机和游戏者谁先报数 */
	{
		tol = Input(tol); 	     /* 若随机数为1，则游戏者先报数 */
	}
	while (tol < 30) 			/* 若未到达游戏结束条件，则继续报数 */
	{
		tol = ControlCompter(tol);
		if (tol == 30)           /* 计算机先报到30，则计算机获胜 */
		{
			printf("Player lose!\n");
		}
		else                       /* 游戏者先报到30，则游戏者获胜 */
		{
			tol = Input(tol);
			if (tol >= 30)   /* 若人报的数是30（或超过30），则游戏者获胜 */
			{
				printf("Computer lose!\n");
			}
		}
	}
	printf("Game over!\n");
	return 0;
}
/* 函数功能：游戏者报数 */
int Input(int t)
{
	int a;
	do{
		printf("please count:");
		scanf("%d", &a);    /* 输入报数的个数，将决定报的数是加1还是加2 */
		if (a>2 || a<1)
		{
			printf("Error input, again!");
		}
		else
		{
			printf("you count:%d\n", t+a);
		}
	} while (a>2 || a<1);
	return  t+a;			     /* 返回报数已经报到的数值 */
}
/* 函数功能：控制计算机报数 */
int ControlCompter(int  s)
{
	int c;
	printf("computer count:");
	if (s%3 == 1)             /* 若余下的个数除以3，余数为1，则取1 */
	{
		s++;
		printf("%d\n", s);
	}
	else  if (s%3 == 2)       /* 若余下的个数除以3，余数为2，则取2 */
	{
		s += 2;
		printf("%d\n", s);
	}
	else
	{                            /* 随机报数1或2个 */
		c = Rnd() + 1;
		s += c;
		printf("%d\n", s);
	}
	return s;           		 /* 返回报数已经报到的数值 */
}
/* 函数功能：生成随机数，返回值为0或者1 */
int Rnd(void)
{
	srand(time(NULL));       /*也可以用srand((unsigned)time(0));*/
	return  rand()%2;
}
