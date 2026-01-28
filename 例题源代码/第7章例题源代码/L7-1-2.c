#include <stdio.h>
long  Fact(int  n);           /* 函数原型声明 */
int main(void)
{
	int  m;
	long ret;
	printf("Input m:");
	scanf("%d", &m);
	ret = Fact(m);           /* 调用函数Fact()，并将函数的返回值存入ret */
	printf("%d! = %ld\n", m, ret);
	return 0;
}
/* 函数功能：用迭代法计算n! */
long  Fact(int  n)           /* 函数定义 */
{
	int  i;
    long result = 1;
	for (i=2; i<=n; i++)
	{
		result *= i;
	}
	return result;
}
