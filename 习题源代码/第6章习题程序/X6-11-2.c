#include <stdio.h>
int main(void)
{
	unsigned long i = 0, n, term = 1, sum = 0;
	printf("Please enter n:");
	scanf("%lu", &n);
	do{
		i++;
		term = term * i;
		sum = sum + term;
	}while(sum < n);
	printf("m<=%lu\n", i-1);
	return 0;
}
