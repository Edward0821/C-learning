#include <stdio.h>
#define N 4
void InputArray(int (*p)[N], int m, int n);
void OutputArray(int (*p)[N], int m, int n);
int main(void)
{
	int  a[3][4];
	printf("Input 3*4 numbers:\n");
	InputArray(a, 3, 4);   /* 向函数传递二维数组的第0行的地址 */
	OutputArray(a, 3, 4);  /* 向函数传递二维数组的第0行的地址 */
	return 0;
}

/* 形参声明为指向列数已知的二维数组的行指针，输入数组元素值 */
void InputArray(int (*p)[N], int m, int n)
{
	int i, j;
	for(i = 0; i<m; i++)
	{
		for(j = 0; j<n; j++)
		{
			scanf("%d", *(p+i)+j);
		}
	}
}
/* 形参声明为指向列数已知的二维数组的行指针，输出数组元素值 */
void OutputArray(int (*p)[N], int m, int n)
{
	int i, j;
	for(i = 0; i<m; i++)
	{
		for(j = 0; j<n; j++)
		{
			printf("%4d", *(*(p+i)+j));
		}
		printf("\n");
	}
}
