#include  <math.h>
#include  <stdio.h>
#define  PI  3.14159       /* 定义宏常量PI */
int main(void)
{
	double r;
    double surface;
    double volume;
    printf("Input r:");
    scanf("%lf", &r);
    surface = 4 * PI * pow(r, 2);
    volume = 4.0/3.0 * PI * pow(r, 3);
    printf("surface = %lf\n", surface);
    printf("volume = %lf\n", volume);
    return 0;
}
