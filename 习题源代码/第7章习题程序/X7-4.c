#include <stdio.h>
unsigned long  Fact(unsigned int  n);
int main(void)
{
	unsigned int  i, n;
	printf("Input n(n>0):");
	scanf("%u", &n);
	for (i = 1; i<=n; i++)
	{
		printf("%d! = %lu\n", i, Fact(i));
	}
	return 0;
}
/* 函数功能：用迭代法计算无符号整型变量n的阶乘，当n>=0时返回n!；否则返回-1 */
unsigned long  Fact(unsigned int  n)
{
	unsigned int  i;
    unsigned long result = 1;
    for (i=2; i<=n; i++)
		result *= i;
    return result;
}
