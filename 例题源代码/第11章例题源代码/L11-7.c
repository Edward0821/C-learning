#include  <stdio.h>
#include  <stdlib.h>
void InputArray(int *p, int m, int n);
double Average(int *p, int m, int n);
int main(void)
{
	int  *p = NULL, m, n;
	double aver;
	printf("How many classes?");
	scanf("%d", &m);                          /* 输入班级数 */
	printf("How many students in a class?");
	scanf("%d", &n);                          /* 输入每班学生人数 */
	p = (int *)calloc(m*n, sizeof(int));  /* 向系统申请内存 */
	if (p == NULL)  /* 确保指针使用前是非空指针，当p为空指针时结束程序运行 */
	{
		printf("No enough memory!\n");
		exit(1);
	}
	InputArray(p, m, n);              /* 输入学生成绩 */
	aver = Average(p, m, n);         /* 计算平均分 */
	printf("aver = %.1f\n", aver);    /* 输出平均分 */
	free(p);                            /* 释放向系统申请的内存 */
	return 0;
}
/* 形参声明为指向二维数组的列指针，输入数组元素值 */
void InputArray(int *p, int m, int n)
{
	int i, j;
	for(i = 0; i<m; i++)        /* m个班 */
	{
		printf("Please enter scores of class %d:\n", i+1);
		for(j = 0; j<n; j++)   /* 每班n个学生 */
		{
			scanf("%d", &p[i*n+j]);
		}
	}
}
/* 形参声明为指针变量，计算数组元素的平均值 */
double Average(int *p, int m, int n)
{
	int i, j, sum = 0;
	for(i = 0; i<m; i++)       /* m个班 */
	{
		for(j = 0; j<n; j++)  /* 每班n个学生 */
		{
			sum = sum + p[i*n+j];
		}
	}
	return (double)sum / (m*n);
}
