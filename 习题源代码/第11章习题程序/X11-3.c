#include <stdio.h>
int main(void)
{
	int n;
	static char *monthName[]={  "Illegal month", "January", "February",
								"March", "April", "May", "June", "July",
								"August", "September", "October",
								"November", "December"};
	printf("Input month number:");
	scanf("%d", &n);
	if ((n <= 12) && (n >= 1))
	{
		printf("month %d is %s\n", n, monthName[n]);/* 输出相应月份 */
	}
	else
	{
		printf("%s\n", monthName[0]);		 /* 输出错误提示信息 */
	}
	return 0;
}
