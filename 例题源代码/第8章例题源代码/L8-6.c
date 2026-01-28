#include <stdio.h>
#define N 40
int ReadScore(int score[]);       /* ReadScore()函数原型 */
int FindMax(int score[], int n);  /* FindMax()函数原型 */
int main(void)
{
	int score[N], max, n;
	n = ReadScore(score);      /*调用函数ReadScore()输入成绩，返回学生人数*/
	printf("Total students are %d\n",n);
	max = FindMax(score, n);   /*调用函数FindMax()计算最高分，返回最高分*/
	printf("The highest score is %d\n",max);
	return 0;
}
/* 函数功能：输入学生某门课的成绩，当输入负值时，结束输入，返回学生人数 */
int ReadScore(int score[])     /* ReadScore()函数定义 */
{
	int i = -1;         /*i初始化为-1，循环体内增1后可保证数组下标从0开始*/
	do{
		i++;
		printf("Input score:");
		scanf("%d", &score[i]);
	} while (score[i] >= 0);    /* 输入负值时结束成绩输入 */
	return i;                      /* 返回学生人数 */
}
/* 函数功能：计算最高分 */
int FindMax(int score[], int n)/* FindMax()函数定义 */
{
	int max, i;
	max = score[0];	           /* 假设score[0]值为当前最大值 */
	for (i=1; i<n; i++)
	{
		if (score[i] > max)      /* 若score[i]值较大 */
		{
			max = score[i];      /* 则用score[i]值替换当前最大值 */
		}
	}
	return max;                    /* 返回最高分 */
}
