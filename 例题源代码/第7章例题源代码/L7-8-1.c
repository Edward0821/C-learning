#include <stdio.h>
void Swap(int a, int b);
int main(void)
{
	int a, b;
	printf("Input a, b:");
	scanf("%d,%d", &a, &b);
	Swap(a, b);
	printf("In main():a = %d, b = %d\n", a, b);
	return 0;
}
void Swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("In Swap():a = %d, b = %d\n", a, b);
}
