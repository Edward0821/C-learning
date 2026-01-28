#include <stdio.h>
#define N 40
int Average(int score[], int n);     /* Average()函数原型 */
void ReadScore(int score[], int n); /* ReadScore()函数原型 */
int main(void)
{
	int score[N], aver, n;
	printf("Input n:");
	scanf("%d", &n);
	ReadScore(score, n);          /* 数组名作为函数实参调用函数ReadScore() */
	aver = Average(score, n);    /* 数组名作为函数实参调用函数Average() */
	printf("Average score is %d\n",aver);
	return 0;
}
/* 函数功能： 计算n个学生成绩的平均分 */
int Average(int score[], int n) /* Average()函数定义 */
{
	int i, sum = 0;
	for (i=0; i<n; i++)
	{
		sum += score[i];
	}
	return  sum / n;
}
/* 函数功能：输入n个学生的某门课成绩 */
void ReadScore(int score[], int n)  /* ReadScore()函数定义 */
{
	int i;
	printf("Input score:");
	for (i=0; i<n; i++)
	{
		scanf("%d", &score[i]);
	}
}
