#include <stdio.h>
int main(void)
{
	int   i, n;
	long  p = 1;        /* 因阶乘值取值范围较大，故p定义为长整型，并赋初值1 */
	printf("Please enter n:");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		p = p * i;                  	/* 做累乘运算 */
	}
	printf("%d! = %ld\n", n, p); 	/* 以长整型格式输出n的阶乘值 */
	return 0;
}
