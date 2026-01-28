#include <stdio.h>
int main(void)
{
	int a;
	printf("Input an integer number:");
	scanf("%d", &a);
	if (0 == a%2)
	{
		printf("a is an even number\n");
	}
	else
	{
		printf("a is an odd number\n");
	}
	return 0;
}

