#include  <stdio.h>
int main(void)
{
	int  year, flag;
	printf("Input a year:");
	scanf("%d", &year);
	flag = (year%4==0 && 0!=year%100 || 0==year%400) ? 1 : 0;
	if (flag)
	{
		printf("%d is a leap year!\n", year);      /*打印"是闰年"*/
	}
	else
	{
		printf("%d is not a leap year!\n", year);  /* 打印"不是闰年"*/
	}
	return 0;
}
