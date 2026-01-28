#include <stdio.h>
void MaxMinExchang(int a[], int n);
int FindMaxPos(int s[], int n);
int FindMinPos(int s[], int n);
int main(void)
{
	int i, a[10];
	printf("Input 10 numbers:");
	for (i=0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
	MaxMinExchang(a, 10);
	printf("Exchang results:");
	for (i=0; i<10; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
	return 0;
}
/* 函数功能：将数组中的最大数与最小数位置互换 */
void MaxMinExchang(int a[], int n)
{
	int  maxPos, minPos, temp;
	maxPos = FindMaxPos(a, n);
	minPos = FindMinPos(a, n);
	temp = a[maxPos];
	a[maxPos] = a[minPos];
	a[minPos] = temp;
}
/* 函数功能：计算数组中的最大值在数组中的下标位置 */
int FindMaxPos(int s[], int n)
{
	int maxPos = 0, max = s[0], i;
	for (i=1; i<n; i++)
	{
		if (s[i] > max)
		{
			max = s[i];
			maxPos = i;
		}
	}
	return maxPos;
}
/* 函数功能：计算数组中的最小值在数组中的下标位置 */
int FindMinPos(int s[], int n)
{
	int minPos = 0, min = s[0], i;
	for (i=1; i<n; i++)
	{
		if (s[i] < min)
		{
			min = s[i];
			minPos = i;
		}
	}
	return minPos;
}
