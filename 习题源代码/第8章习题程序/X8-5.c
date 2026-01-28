#include <stdio.h>
#define N 40
int ReadScore(int score[], long num[]);
int FindMax(int score[], int n);
int main(void)
{
	int score[N], maxNum, n;
	long num[N];
	n = ReadScore(score, num);      /* 输入成绩，返回学生人数 */
	printf("Total students are %d\n", n);
	maxNum = FindMax(score, n);        /* 计算并返回最高分所在数组的下标 */
	printf("The highest is %ld, ID is %d\n", num[maxNum], score[maxNum]);
	return 0;
}
/* 函数功能：输入学生某门课的成绩，当输入负值时，结束输入，返回学生人数 */
int ReadScore(int score[], long num[])
{
	int i = -1;
	do{
		i++;
		printf("Input student's ID and score:");
		scanf("%ld%d", &num[i], &score[i]);
	}while (score[i] >= 0 && num[i]>=0);
	return i;
}
/* 函数功能：计算并返回最高分所在数组的下标 */
int FindMax(int score[], int n)
{
	int max = score[0], i, maxNum = 0;
	for (i=1; i<n; i++)
	{
		if (score[i] > max)
		{
			max = score[i];
			maxNum = i;
		}
	}
	return maxNum;
}
