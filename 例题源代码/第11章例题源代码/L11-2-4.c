#include <stdio.h>
void InputArray(int *pa, int n);
void OutputArray(int *pa, int n);
int main(void)
{
	int  a[5];
	int *p = a;
	printf("Input five numbers:");
	InputArray(p, 5);                 /* 用指向一维数组的指针变量作为函数实参 */
	OutputArray(p, 5);                /* 用指向一维数组的指针变量作为函数实参 */
	return 0;
}
void InputArray(int *pa, int n)   /* 形参声明为指针变量，输入数组元素值 */
{
   int i;
	for (i=0; i<n; i++)
	{
		scanf("%d", &pa[i]);  /* 形参声明为指针变量时也可以按下标方式访问数组 */
	}
}
void OutputArray(int *pa, int n)  /* 形参声明为指针变量，输出数组元素值 */
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%4d",pa[i]);  /* 形参声明为指针变量时也可以按下标方式访问数组 */
	}
	printf("\n");
}


