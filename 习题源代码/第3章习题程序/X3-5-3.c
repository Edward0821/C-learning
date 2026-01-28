#include  <math.h>
#include  <stdio.h>
const double pi = 3.14159;    /* 定义双精度实型的const常量pi */
int main(void)
{
	double r;
    double surface;
    double volume;
    printf("Input r:");
    scanf("%lf", &r);
    surface = 4 * pi * pow(r, 2);
    volume = 4.0/3.0 * pi * pow(r, 3);
    printf("surface = %lf\n", surface);
    printf("volume = %lf\n", volume);
    return 0;
}
