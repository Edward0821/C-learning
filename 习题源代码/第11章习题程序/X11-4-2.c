#include <stdio.h>
#define N 10
void  Swap(int *x, int *y);
void Transpose(int (*a)[N], int n);
void InputMatrix(int (*a)[N], int n);
void PrintMatrix(int (*a)[N], int n);
int main(void)
{
	int s[N][N], n;
	printf("Input n:");
	scanf("%d", &n);
	InputMatrix(s, n);
	Transpose(s, n);
	printf("The transposed matrix is:\n");
	PrintMatrix(s, n);
	return 0;
}
/* 函数功能：交换两个整型数的值 */
void  Swap(int *x, int *y)
{
	int  temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
/* 函数功能：计算n*n矩阵的转置矩阵 */
void Transpose(int (*a)[N], int n)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=i; j<n; j++)
		{
			Swap(*(a+i)+j, *(a+j)+i);
		}
	}
}
/* 函数功能：输入n*n矩阵的值 */
void InputMatrix(int (*a)[N], int n)
{
	int i, j;
	printf("Input %d*%d matrix:\n", n, n);
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%d", *(a+i)+j);
		}
	}
}
/* 函数功能：输出n*n矩阵的值 */
void PrintMatrix(int (*a)[N], int n)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%d\t", *(*(a+i)+j));
		}
		printf("\n");
	}
}
