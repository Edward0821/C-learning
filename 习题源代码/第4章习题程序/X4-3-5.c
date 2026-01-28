#include <stdio.h>
int main(void)
{
	char a,b;
	int c;
	scanf("%c%*c%c%*c%d", &a, &b, &c);
	printf("%c,%c,%d\n", a, b, c);
	return 0;
}
