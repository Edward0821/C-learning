#include <stdio.h>
int main(void)
{
	int  x, y, z;
	printf("Man\tWomen\tChildren\n");
	for (x=0; x<=16; x++)
	{
		for (y=0; y<=25; y++)
		{
			z = 30 - x - y;
			if (50 == 3*x+2*y+z)
			{
				printf("%3d\t%5d\t%8d\n", x, y, z);
			}
		}
	}
	return 0;
}
