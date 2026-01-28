#include <stdio.h>
int main(void)
{
	int  x;
	int find = 0;                      /* 置找到标志变量为假 */
	for (x=1; !find; x++)             /* find为假时继续循环 */
	{
		if (x%5==1 && x%6==5 && x%7==4 && x%11==10)
		{
			printf("x = %d\n", x);
			find = 1;                 /* 置找到标志变量为真 */
		}
	}
	return 0;
}
