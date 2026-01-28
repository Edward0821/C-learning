#include <stdio.h>
void InputArray(int a[], int n);
void OutputArray(int a[], int n);
int main(void)
{
	int  a[5];
	int *p = a;
	printf("Input five numbers:");
	InputArray(p, 5);                 /* 用指向一维数组的指针变量作为函数实参 */
	OutputArray(p, 5);                /* 用指向一维数组的指针变量作为函数实参 */
	return 0;
}
void InputArray(int a[], int n)   /* 形参声明为数组，输入数组元素值 */
{
	int  i;
	for (i=0; i<n; i++)
	{
		scanf("%d", a+i);            /* 这里a+i等价于&a[i] */
	}
}
void OutputArray(int a[], int n) /* 形参声明为数组，输出数组元素值 */
{
	int  i;
	for (i=0; i<n; i++)
	{
		printf("%4d", *(a+i));      /* 这里*(a+i)等价于a[i] */
	}
	printf("\n");
}


