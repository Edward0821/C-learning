#include <stdio.h>
#include <math.h>
#define EPS  1e-1
int main(void)
{
	float a, b, c;
	printf("Input a,b,c:");
	scanf("%f,%f,%f", &a, &b, &c);
	if (a+b>c && b+c>a && a+c>b)
	{
		if (fabs(a-b)<=EPS || fabs(b-c)<=EPS|| fabs(c-a)<=EPS)
		{
			printf("等腰三角形\n");
		}
		else if (fabs(a*a+b*b-c*c)<=EPS	 || fabs(a*a+c*c-b*b)<=EPS
			|| fabs(c*c+b*b-a*a)<=EPS)
		{
			printf("直角三角形\n");
		}
		else
		{
			printf("一般三角形\n");
		}
	}
	else
	{
		printf("不是三角形\n");
	}
	return 0;
}
