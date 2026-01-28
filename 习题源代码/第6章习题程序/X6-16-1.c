#include <stdio.h>
int main(void)
{
	int x, y, z;
	for (x=0; x<=100; x++)
	{
		for (y=0; y<=100; y++)
		{
			for (z=0; z<=100; z++)
			{
				if (x+y+z==100 && 5*x+3*y+z/3.0==100)
				{
					printf("x=%d, y=%d, z=%d\n", x, y, z);
				}
			}
		}
	}
	return 0;
}
