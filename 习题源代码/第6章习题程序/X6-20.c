#include <stdio.h>
int main(void)
{
	int  i, j, k, m;
	for (i=0; i<=9; i++)
	{
		for (j=0; j<=9; j++)
		{
			if (i != j)
			{
				k = i * 1000 + i * 100 + j * 10 + j;
				for (m=31; m*m<=k ;m++)
				{
					if (m * m == k)
					{
						printf("k=%d, m=%d\n", k, m);
					}
				}
			}
		}
	}
	return 0;
}
