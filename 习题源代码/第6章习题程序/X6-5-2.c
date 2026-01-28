#include <stdio.h>
int main(void)
{
	int    upper, step;
	float  fahr = -40, celsius;

	upper = 110;
	step = 10;
	while (fahr <= upper)
	{
       	celsius = 5.0 / 9 * (fahr - 32);
		printf("%4.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
	}
	return 0;
}
