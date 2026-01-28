#include <stdio.h>
int main(void)
{
	int  i, j, k;
	for (i=1; i<=9; i++)
		for (j=0; j<=9; j++)
			for (k=0; k<=9; k++)
			{
				if (i*100+j*10+k == i*i*i+j*j*j+k*k*k)
				{
					printf("%6d", i*100+j*10+k);
				}
			}
    printf("\n");
    return 0;
}
