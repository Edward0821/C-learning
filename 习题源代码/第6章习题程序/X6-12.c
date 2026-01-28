#include <stdio.h>
int main(void)
{
	int  i = 0, n, sum = 0;
	printf("Input a number:");
	scanf("%d", &n);
	while(n > 0)
	{
		sum = sum + n;
		printf("Input a number:");
		scanf("%d", &n);
		i++;
	}
	printf("sum = %d, count = %d\n", sum, i);
	return 0;
}
