#include <stdio.h>
int main(void)
{
	int  fahr;
	float celsius;
	for (fahr=-40; fahr<=110; fahr=fahr+10)
	{
		celsius = 5.0 / 9 * (fahr - 32);
		printf("%4d\t%6.1f\n", fahr, celsius);
	}
	return 0;
}
