#include <stdio.h>
int main(void)
{
	int  i = 0, n, sum = 0;
	printf("Input a number:");
	scanf("%d", &n);
	while(n != 0)
	{
		if (n > 0)
		{
			sum = sum + n;
			i++;
		}
		printf("Input a number:");
		scanf("%d", &n);
	}
	printf("sum = %d, count = %d\n", sum, i);
	return 0;
}
