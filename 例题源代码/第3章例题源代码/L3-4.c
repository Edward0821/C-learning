#include  <stdio.h>
#define  PI  3.14159       /* 定义宏常量PI */
int main(void)
{
	double r;
	printf("Input r:");
	scanf("%lf", &r);
	printf("circumference = %f\n", 2*PI*r); /*编译时PI被替换为3.14159*/
	printf("area = %f\n", PI*r*r); /*编译时PI被替换为3.14159*/
	return 0;
}
