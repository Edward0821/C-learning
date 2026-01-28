#include  <stdio.h>
void  Swap(int *x, int *y);
int main(void)
{
	int  a, b;
	printf("Please enter a,b:");
	scanf("%d,%d", &a, &b);
	printf("Before swap: a = %d, b = %d\n", a, b);/* 打印交换前的a,b */
	Swap(&a, &b);                                  /* 按地址调用函数Swap() */
	printf("After swap: a = %d, b = %d\n", a, b);/* 验证a,b是否互换 */
	return 0;
}
/* 函数功能：交换两个整型数的值 */
void  Swap(int *x, int *y)
{
	int  temp;
	temp = x;            /* 执行图7-5(b)中的步骤① */
	x = y;                /* 执行图7-5(b)中的步骤② */
	y = temp;            /* 执行图7-5(b)中的步骤③ */
}
