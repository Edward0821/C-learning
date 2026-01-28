#include  <stdio.h>
int main(void)
{
	int  x = 153, b0, b1, b2, sum;
	b2 = x / 100;                   			/* 计算百位数字 */
	b1 = (x - b2 * 100) / 10;     			/* 计算十位数字 */
	b0 = x % 10;                   			/* 计算个位数字 */
	sum = b2 + b1 + b0;
	printf("b2=%d, b1=%d, b0=%d, sum=%d\n", b2, b1, b0, sum);
	return 0;
}

