#include <stdio.h>
long  Fact(int  n);
int main(void)
{
	int  n;
	long result;
	printf("Input n:");
	scanf("%d", &n);
	result = Fact(n);            /* 调用递归函数Fact()计算n! */
	if(result == -1)              /* 处理非法数据 */
		printf("n<0, data error!\n");
	else                            /* 输出n!值 */
		printf("%d! = %ld\n", n, result);
	return 0;
}
/* 函数功能：用递归法计算n!，当n>=0时返回n!，否则返回-1 */
long  Fact(int  n)
{
	long result = 1;
	if (n < 0)                     /* 处理非法数据 */
		return -1;
	else if (n==0 || n==1)       /* 基线情况，即递归终止条件 */
		return 1;
	else                            /* 一般情况 */
		return (n * Fact(n-1)); /* 递归调用，利用(n-1)!计算n! */
}
