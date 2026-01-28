#include <stdio.h>
#define N 40
int Average(int score[], int n);
int ReadScore(int score[]);
int GetAboveAver(int score[], int n);
int main(void)
{
	int score[N], m, n;
	n = ReadScore(score);           /* 输入成绩，返回学生人数 */
	printf("Total students are %d\n", n);
	m = GetAboveAver(score, n);    /* 统计成绩在平均分及其上的学生人数 */
	if (m != -1) printf("Students of above average is %d\n", m);
	return 0;
}
/* 函数功能：若n>0，则计算并返回n个学生成绩的平均分，否则返回-1 */
int Average(int score[], int n)
{
	int i, sum = 0;
	for (i=0; i<n; i++)
	{
		sum += score[i];
	}
	return  n>0 ? sum/n : -1;
}
/* 函数功能：输入学生某门课成绩，当输入成绩为负值时，结束输入，返回学生人数 */
int ReadScore(int score[])
{
	int i = -1;
	do{
		i++;
		printf("Input score:");
		scanf("%d", &score[i]);
	}while (score[i] >= 0);
	return i;
}
/* 函数功能：若n>0，则统计并返回成绩在全班平均分及平均分之上的学生人数，否则返回-1 */
int GetAboveAver(int score[], int n)
{
	int   i, count = 0, aver;
	aver = Average(score, n);  /* 计算并返回打印平均分 */
	if (aver == -1) return -1;
	printf("Average score is %d\n", aver);
	for (i=0; i<n; i++)
	{
		if (score[i] >= aver)  count++;
	}
	return count;
}
