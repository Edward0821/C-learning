#include <stdio.h>
int main(void)
{
	int  i, j, n;
	long p, sum = 0;                /* 累加求和变量sum初始化为0 */
	printf("Input n:");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		p = 1;           /* 每次循环之前都要将累乘求积变量p赋值为1 */
		for (j=1; j<=i; j++)
		{
			p = p * j;               /* 累乘求积 */
		}
		sum = sum + p;               /* 累加求和 */
	}
	printf("1!+2!+…+%d! = %ld\n", n, sum);
	return 0;
}
