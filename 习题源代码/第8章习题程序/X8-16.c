#include<stdio.h>
#define  N  10
void  BubbleSort(int a[], int n);
int main(void)
{
	int i, n, a[N];
	printf("Input n:");
	scanf("%d", &n);
	printf("Input %d numbers:", n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	BubbleSort(a, n);
	printf("Sorting results:");
	for (i=0; i<n; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
	return 0;
}
/* 函数功能：冒泡法实现数组a 的n个元素的升序排序 */
void  BubbleSort(int a[], int n)
{
	int  i, j, temp;
	for (i=0; i<n-1; i++)
	{
		for (j=1; j<n-i; j++)
		{
			if (a[j] < a[j-1])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}
