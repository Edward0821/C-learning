#include <stdio.h>
void Swap(int x, int y);
int main(void)
{
	int a, b;
	printf("Input a, b:");
	scanf("%d,%d", &a, &b);
	Swap(a, b);
	printf("In main():a = %d, b = %d\n", a, b);
	return 0;
}
void Swap(int x, int y)
{
	   int temp;
	   temp = x;
	   x = y;
	   y = temp;
}
