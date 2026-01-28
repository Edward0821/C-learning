#include <stdio.h>
int main(void)
{
	int  m, n, k;
	for (m=1; m<10; m++)            /*外层循环控制行数（被乘数）的变化*/
	{
		for (k=1; k<=4*m-4; k++) /*在第n行先打印4×n-4个空格*/
		{
			printf(" ");           /*输出相应空格使数字右对齐*/
		}
		for (n=m; n<10; n++)       /*内层循环控制列数（乘数）的变化*/
		{
			printf("%4d", m*n);    /*输出第m行n列中的m*n的值*/
		}
		printf("\n");               /*输出换行符,准备打印下一行*/
	}
	return 0;
}
