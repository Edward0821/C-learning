#include <stdio.h>
int Lcm(int a, int b);
int main(void)
{
	int a, b, x;
	printf("Input a,b:");
	scanf("%d,%d", &a, &b);
	x = Lcm(a, b);
	if (x != -1)
	{
		printf("Least Common Multiple of %d and %d is %d\n", a, b, x);
	}
	else
	{
		printf("Input error!\n");
	}
	return 0;
}
/* 计算a和b的最小公倍数*/
int Lcm(int a, int b)
{
	int i;
	if (a <= 0 || b <= 0)		/* 保证输入的参数为正整数 */
	{
		return -1;
	}
	for (i=1; i<b; i++)
	{
		if (i * a % b == 0)
			return i * a;
	}
	return b * a;
}
