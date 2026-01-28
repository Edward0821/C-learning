#include  <stdio.h>
int main(void)
{
	int  x=12, y=8;
	printf("\n%5d%5d%5d", !x, x||y, x&&y);
	printf("\n%5u%5d%5d", ~x, x|y, x&y);
	printf("\n%5d%5d%5d\n", ~x, x|y, x&y);
	return 0;
}
