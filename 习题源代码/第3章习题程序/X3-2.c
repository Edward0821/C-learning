#include  <math.h>
#include  <stdio.h>
int main(void)
{
	int  x, b0, b1, b2, y;
	printf("Input x:");
	scanf("%d", &x);
	x = (int)fabs(x);
	b2 = x / 100;                   		/* 计算百位数字 */
	b1 = (x - b2 * 100) / 10;     			/* 计算十位数字 */
	b0 = x % 10;                   			/* 计算个位数字 */
	y = b2 + b1*10 + b0*100;
	printf("y =%d \n",y);
	return 0;
}
