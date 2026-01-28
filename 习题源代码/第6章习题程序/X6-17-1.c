#include <stdio.h>
int main(void)
{
	int x, y, z, count = 0;
	for (x=1; x<50; x++)
	{
		for (y=1; y<50; y++)
		{
			for (z=1; z<50; z++)
			{
				if (x+y+z==50 && 10*x+5*y+z==100)
				{
					count++;
					printf("x = %d, y = %d, z = %d\n", x, y, z);
				}
			}
		}
	}
	printf("count = %d\n", count);
	return 0;
}
