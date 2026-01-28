#include <stdio.h>
int Magic(int m);
int main(void)
{
	int m, ret;
	printf("Input a sum:");
	scanf("%d", &m);
	ret = Magic(m);
	if (ret != 1)
	{
		printf("The sum you calculated is wrong!\n");
	}
	return 0;
}
int Magic(int m)
{
	int a, b, c, n;
	for (a=1; a<9; a++)
	{
		for (b=1; b<9; b++)
		{
			for(c=1; c<9; c++)
			{
				n = 122 * a +212 * b +221 * c;
				if (m == n)
				{
					printf("The number is %d\n", 100*a+10*b+c);
					return 1;
				}
			}
		}
	}
	return 0;
}
