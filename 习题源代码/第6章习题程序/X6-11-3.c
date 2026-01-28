#include <stdio.h>
int main(void)
{
	unsigned long i, n, term = 1, sum = 0;
	int flag = 0;
	printf("Please enter n:");
	scanf("%lu", &n);
	for (i=1; !flag; i++)
	{
		term = term * i;
		sum = sum + term;
		if (sum >= n)
		{
			flag = 1;
			printf("m <= %lu\n", i-1);
		}
	}
	return 0;
}
