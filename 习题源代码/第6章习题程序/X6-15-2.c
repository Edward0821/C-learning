#include <stdio.h>
int main(void)
{
	int x, y;
	for (x = 1; x <= 97; x++)
	{
		y = 98 - x;
		if (2 * x + 4 * y == 386)
		{
			printf("x = %d, y = %d\n", x, y);
		}
	}
	return 0;
}
