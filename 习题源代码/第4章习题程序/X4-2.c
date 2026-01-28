#include  <stdio.h>
int main(void)
{
	long a, b;
	float x, y;
	scanf("%d, %d", &a, &b);
	scanf("%f, %f", &x, &y);
	printf("a = %d, b = %d\n", a, b);
	printf("x = %5.2f, y = %5.2f\n", x, y);
	return 0;
}
