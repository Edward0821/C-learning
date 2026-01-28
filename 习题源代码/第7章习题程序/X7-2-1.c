#include <stdio.h>
int Max(int a, int b);
int main(void)
{
	int a, b, c;
	printf("Input a,b:");
	scanf("%d,%d", &a, &b);
	printf("max = %d\n", Max(a, b));
	return 0;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}
