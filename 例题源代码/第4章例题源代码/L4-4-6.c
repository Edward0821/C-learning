#include  <stdio.h>
int main(void)
{
	int  a, b;
	scanf("%d%*c%d", &a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
