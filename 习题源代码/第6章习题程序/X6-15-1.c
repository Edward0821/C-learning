#include <stdio.h>
int main(void)
{
	int x, y;
	for (x=1; x<=98; x++)
	{
		for (y=1; y<98; y++)
		{
			if (x+y==98 && 2*x+4*y==386)
			{
				printf("x = %d, y = %d\n", x, y);
			}
		}
	}
	return 0;
}
