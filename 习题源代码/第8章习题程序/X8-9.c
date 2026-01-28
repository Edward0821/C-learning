#include <stdio.h>
#define  N   10
void InputMatrix(int a[N][N], int n);
int AddDiagonal(int a[N][N], int n);
int main(void)
{
	int a[N][N], n, sum;
	printf("Input n:");
	scanf("%d", &n);
	InputMatrix(a, n);
	sum = AddDiagonal(a, n);
    printf("sum = %d\n", sum);
    return 0;
}
/*  函数功能： 输入n×n矩阵的元素，存于数组a中 */
void InputMatrix(int a[N][N], int n)
{
	int i, j;
	printf("Input %d*%d matrix:\n", n, n);
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
       	{
			scanf("%d",&a[i][j]);
       	}
	}
}
/*  函数功能： 计算n×n矩阵中两条对角线上的元素之和 */
int AddDiagonal(int a[N][N], int n)
{
	int i, j, sum = 0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (i == j || i+j == n-1)	sum = sum + a[i][j];
		}
    }
    return sum;
}
