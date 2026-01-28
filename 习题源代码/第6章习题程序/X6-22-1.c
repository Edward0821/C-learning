#include  <math.h>
#include <stdio.h>
#define   CONST  1.42e8     			    /*定义符号常量CONST值为1.42e8 */
int main(void)
{
	int      n;
	double  term, sum = 0;
	for (n=1; n<=64; n++)
	{
		term = pow(2, n-1);
		sum = sum + term;
	}
	printf("sum = %e\n", sum);        	/* 打印总麦粒数 */
	printf("volum = %e\n", sum/CONST);	/* 打印折合的总麦粒体积数 */
	return 0;
}
