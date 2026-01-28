#include <stdio.h>
void InputArray(int *p, int m, int n);
void OutputArray(int *p, int m, int n);
int main(void)
{
	int  a[3][4];
	printf("Input 3*4 numbers:\n");
	InputArray(*a, 3, 4);   /* 向函数传递二维数组的第0行第0列的地址 */
	OutputArray(*a, 3, 4);  /* 向函数传递二维数组的第0行第0列的地址 */
	return 0;
}
/* 形参声明为指向二维数组的列指针，输入数组元素值 */
void InputArray(int *p, int m, int n)
{
	int i, j;
	for(i = 0; i<m; i++)
	{
		for(j = 0; j<n; j++)
		{
			scanf("%d", &p[i*n+j]);
		}
	}
}
/* 形参声明为指向二维数组的列指针，输出数组元素值 */
void OutputArray(int *p, int m, int n)
{
	int i, j;
	for(i = 0; i<m; i++)
	{
		for(j = 0; j<n; j++)
		{
			printf("%4d", p[i*n+j]);
		}
		printf("\n");
	}
}
