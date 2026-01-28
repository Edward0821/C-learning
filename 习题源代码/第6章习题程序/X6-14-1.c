#include <stdio.h>
int main(void)
{
	int  x, y, z;
	printf("Man\tWomen\tChildren\n");
	for (x=0; x<=30; x++)
	{
		for (y=0; y<=30; y++)
		{
			for (z=0; z<=30; z++)
			{
				if (x+y+z==30 && 3*x+2*y+z==50)
				{
					printf("%3d\t%5d\t%8d\n", x, y, z);
				}
			}
		}
	}
	return 0;
}
