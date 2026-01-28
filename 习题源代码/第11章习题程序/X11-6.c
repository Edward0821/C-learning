#include <stdio.h>
#define M 10
#define N 10
void InputMatrix(int *p, int m, int n);
int FindMax(int *p, int m, int n, int *pRow, int *pCol);
int main(void)
{
	int a[M][N], m, n, row, col, max;
	printf("Input m, n:");
	scanf("%d,%d", &m, &n);
	InputMatrix(*a, m, n);
	max = FindMax(*a, m, n, &row, &col);
	printf("max = %d, row = %d, col = %d\n", max, row, col);
	return 0;
}
/* 函数功能：输入m*n矩阵的值 */
void InputMatrix(int *p, int m, int n)
{
	int i, j;
	printf("Input %d*%d array:\n", m, n);
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%d", &p[i*n+j]);
		}
	}
}
/* 函数功能：在m*n矩阵中查找最大值及其所在的行列号 */
int FindMax(int *p, int m, int n, int *pRow, int *pCol)
{
	int i, j, max = p[0];
	*pRow = 0;
	*pCol = 0;
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			if (p[i*n+j] > max)
			{
				max = p[i*n+j];
				*pRow = i;              /*记录行下标*/
				*pCol = j;              /*记录列下标*/
			}
		}
	}
	return max;
}
