#include <stdio.h>
long Func(int n);
int main(void)
{
	int i, n;
	printf("Input n:");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		printf("%d! = %ld\n", i, Func(i));
	}
	return 0;
}
long Func(int n)
{
	auto long p = 1;		/* 定义自动变量 */
	p = p * n;
	return p;
}
