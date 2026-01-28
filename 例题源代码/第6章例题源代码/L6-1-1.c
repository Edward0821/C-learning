#include <stdio.h>
int main(void)
{
	int  i, n, sum;
	printf("Input n:");
	scanf("%d", &n);
	sum = 0;                     /* 累加和变量初始化为0 */
	for (i=1; i<=n; i++)
	{
		sum = sum + i;	      /* 做累加运算 */
	}
	printf("sum = %d\n", sum);
	return 0;
}
