#include  <stdio.h>
int main(void)
{
	int  a, b;
	scanf("%2d%*2d%2d", &a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
