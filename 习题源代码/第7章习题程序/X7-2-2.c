#include <stdio.h>
int Max(int a, int b);
int main(void)
{
	int a, b, c;
	printf("Input a,b:");
	scanf("%d,%d", &a, &b);
	c = Max(a, b);
	printf("max = %d\n", c);
	return 0;
}
int Max(int a, int b)
{
	int c;
	if (a > b) c = a;
	else c = b;
	return a > b ? a : b;
}
