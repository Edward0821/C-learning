#include  <stdio.h>
int main(void)
{
	const double PI = 3.14159;    /* 定义实型的const常量PI */
	double r;
	printf("Input r:");
	scanf("%lf", &r);
	printf("circumference = %f\n", 2*PI*r);
	printf("area = %f\n", PI*r*r);
	return 0;
}
