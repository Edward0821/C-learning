#include  <stdio.h>
#include  <stdlib.h>
void InputArray(int *p, int n);
double Average(int *p, int n);
int main(void)
{
	int  *p = NULL, n;
	double aver;
	printf("How many students?");
	scanf("%d", &n);                          /* 输入学生人数 */
	p = (int *) malloc(n * sizeof(int)); /* 向系统申请内存 */
	if (p == NULL)  /* 确保指针使用前是非空指针，当p为空指针时结束程序运行 */
	{
		printf("No enough memory!\n");
		exit(1);
	}
	printf("Input %d score:", n);
	InputArray(p, n);                     /* 输入学生成绩 */
	aver = Average(p, n);                 /* 计算平均分 */
	printf("aver = %.1f\n", aver);      /* 输出平均分 */
	free(p);                                /* 释放向系统申请的内存 */
	return 0;
}
/* 形参声明为指针变量，输入数组元素值 */
void InputArray(int *p, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		scanf("%d", &p[i]);
	}
}
/* 形参声明为指针变量，计算数组元素的平均值 */
double Average(int *p, int n)
{
	int i, sum = 0;
	for (i=0; i<n; i++)
	{
		sum = sum + p[i];
	}
	return (double)sum / n;
}
