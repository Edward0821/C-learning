#include <stdio.h>
#include  <math.h>
int main(void)
{
	float  a, b, c, s, area;
	printf("Input a,b,c:");
	scanf("%f,%f,%f", &a, &b, &c);
	if (a+b>c && b+c>a && a+c>b)
	{
		s = (float)(a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("area = %f\n", area);
	}
	else
	{
		printf("It is not a triangle\n");
	}
	return 0;
}
