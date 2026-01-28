#include <stdio.h>
int main()
{
	printf("输入需要换算的英尺，英寸,""如输入\"5 7\"表示5英尺7英寸"); 
	
	double inch;
	double cun;
	scanf("%lf %lf",&inch,&cun);
	printf("结果为：%f米。\n",
	((inch+cun/12)*0.3048));
	return 0;
 } 
