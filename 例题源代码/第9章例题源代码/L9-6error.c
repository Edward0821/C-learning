#include  <stdio.h>
void  Swap(int x, int y);
int main(void)
{
	int  a, b;
	printf("Please enter a,b:");
	scanf("%d,%d", &a, &b);
	printf("Before swap: a = %d, b = %d\n", a, b);/* 打印交换前的a,b */
	Swap(a, b);                                      /* 按值调用函数Swap() */
	printf("After swap: a = %d, b = %d\n", a, b);/* 打印交换后的a,b */
	return 0;
}
void  Swap(int x, int y)
{
	int  temp;
	temp = *x;            /* 执行图9-4(b)中的步骤① */
	*x = *y;              /* 执行图9-4(b)中的步骤② */
	*y = temp;            /* 执行图9-4(b)中的步骤③ */
}
