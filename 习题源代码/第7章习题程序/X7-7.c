#include <stdio.h>
int Coconut(int n);
int main(void)
{
	printf("y = %d\n", Coconut(5));
	return 0;
}
int Coconut(int n)
{
	int   i = 1;
	float x = 1, y;
	y = n * x + 1;
	do{
		y = y * n / (n-1) + 1;
		i++;
		if (y != (int)y)
		{
			x = x + 1;
			y = n * x + 1;
			i = 1;
		}
	}while (i < n);
	return (int)y;
}
