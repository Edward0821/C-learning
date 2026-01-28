#include<stdio.h>
#define  ROW 10
#define  COL 10
void  InputMatrix(int a[ROW][COL], int m, int n);
void  AddMatrix(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL],
				int m, int n);
void  PrintMatrix(int a[ROW][COL], int m, int n);
int main(void)
{
	int a[ROW][COL], b[ROW][COL], c[ROW][COL], m, n;
	printf("Input m, n:");
	scanf("%d,%d", &m, &n);
	printf("Input %d*%d matrix a:\n", m, n);
	InputMatrix(a, m, n);
	printf("Input %d*%d matrix b:\n", m, n);
	InputMatrix(b, m, n);
	AddMatrix(a, b, c, m, n);
	printf("Results:\n");
	PrintMatrix(c, m, n);
	return 0;
}
/*  函数功能： 输入m×n矩阵的元素值，存于数组a中 */
void  InputMatrix(int a[ROW][COL], int m, int n)
{
	int i, j;
	for (i=0; i<m; i++)
	{
        for (j=0; j<n; j++)
        {
			scanf("%d", &a[i][j]);
        }
	}
}
/*  函数功能：计算m×n矩阵之和，即对应位置元素之和，结果存于数组c中 */
void  AddMatrix(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL],
				int m, int n)
{
	int i, j;
	for (i=0; i<m; i++)
	{
        for (j=0; j<n; j++)
        {
			c[i][j] = a[i][j] + b[i][j];
        }
	}
}
/* 函数功能： 输出m×n矩阵的元素值 */
void  PrintMatrix(int a[ROW][COL], int m, int n)
{
	int i, j;
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
        {
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
}
