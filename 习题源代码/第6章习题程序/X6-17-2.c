#include <stdio.h>
int main(void)
{
	int x, y, z, count = 0;
	for (x = 1; x <= 9; x++)
	{
		for (y = 1; y <= 19; y++)
		{
			z = 50 - x - y;
			if (10*x + 5*y + z == 100)
			{
				count++;
				printf("x = %d, y = %d, z = %d\n", x, y, z);
			}
		}
	}
	printf("count = %d\n", count);
	return 0;
}
