#include <stdio.h>
int main(void)
{
	int i, n;
	long sum = 0, p = 1;   /* 累加求和及累乘求积变量分别初始化为0和1 */
	printf("Input n:");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		p = p * i;      /* 计算累加项（即通项） */
		sum = sum + p;
	}
	printf("1!+2!+…+%d! = %ld\n", n, sum);
	return 0;
}
