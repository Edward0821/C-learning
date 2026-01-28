#include  <stdio.h>
int main(void)
{
	double r;
	printf("Input r:");   /* 提示用户输入半径的值*/
	scanf("%lf", &r);     /* 以双精度实型格式从键盘输入半径的值 */
	printf("circumference = %f\n", 2*3.14159*r);
	printf("area = %f\n", 3.14159*r*r);
	return 0;
}
