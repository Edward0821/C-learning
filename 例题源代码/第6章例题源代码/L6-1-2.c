#include <stdio.h>
int main(void)
{
	int  i, n, sum;
	printf("Input n:");
	scanf("%d", &n);
	sum = 0;                    /* 累加和变量初始化为0 */
	i = 1;
	while (i <= n)
	{
		sum = sum + i;          /* 做累加运算 */
		i++;	/* 累加计数器加1 */
	}
	printf("sum = %d\n", sum);
	return 0;
}
