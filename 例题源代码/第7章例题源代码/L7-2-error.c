#include <stdio.h>
long  Fact(int  n);
int main(void)
{
	int  m;
	long ret;
	printf("Input m:");
	scanf("%d", &m);
	ret = Fact(m);
	printf("%d! = %ld\n", m, ret);
	return 0;
}
/* 函数功能：用迭代法计算n! */
long  Fact(int  n)
{
	int  i;
    long result = 1;
	if (n < 0)             /* 增加对函数入口参数合法性的检查 */
    {
		printf("Input data error!\n");
	}
    else
    {
        for (i=2; i<=n; i++)
            result *= i;
        return result;
    }
}
