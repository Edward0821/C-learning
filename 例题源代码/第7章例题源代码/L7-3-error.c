#include <stdio.h>
unsigned long  Fact(unsigned int  n);
int main(void)
{
	int  m;
	long ret;
	printf("Input m:");
	scanf("%d", &m);
	ret = Fact(m);
	if (ret == -1)          /* 增加对函数返回值的检验 */
		printf("Input data error!\n");
	else
		printf("%d! = %ld\n", m, ret);
	return 0;
}
/* 函数功能：用迭代法计算无符号整型变量n的阶乘，当n>=0时返回n!；否则返回-1 */
unsigned long  Fact(unsigned int  n)
{
	unsigned int  i;
    unsigned long result = 1;
	if (n < 0)
    {
		return -1;
	}
    else
    {
        for (i=2; i<=n; i++)
            result *= i;
        return result;
    }
}
