#include  <stdio.h>
int main(void)
{
	int  m, n;
	for (m=1; m<10; m++)            /*外层循环控制行数（被乘数）的变化*/
	{
		for (n=1; n<10; n++)        	/*内层循环控制列数（乘数）的变化*/
		{
			printf("%4d", m*n);         	/*输出第m行n列中的m*n的值*/
		}
		printf("\n");                     	/*输出换行符,准备打印下一行*/
	}
	return 0;
}
