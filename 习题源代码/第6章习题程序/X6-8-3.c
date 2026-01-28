#include  <math.h>
#include <stdio.h>
int main(void)
{
	double  pi, sum = 0, term, sign = 1.0;/*sum赋初值0，分子sign赋初值*/
	int     count = 0, n = 1;  	/*计数器变量count赋初值0，分母n赋初值1*/
	term = 1.0;                     /*为先判断后执行的需要，累加项term也赋初值*/
	for (;fabs(term) >= 1e-4;)	/*判断累加项是否满足循环终止条件*/
	{
		term = sign / n;        	/*累加项由分子sign除以分母n得到*/
		sum = sum + term;       	/*将累加项累加到累加和变量sum中去*/
		count ++;                	/*计数器变量count计数加1*/
		sign = -sign;           	/*分子的变化规律*/
		n = n + 2;               	/*分母的变化规律*/
	}
	pi = sum * 4;
	printf("pi = %f\ncount = %d\n", pi, count);
	return 0;
}
