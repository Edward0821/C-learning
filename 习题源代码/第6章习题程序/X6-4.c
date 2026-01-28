#include <stdio.h>
int main(void)
{
	int   i, n;
	printf("Please enter n:");
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		printf("%d*%d = %d\n", i, i, i*i); /*输出所有数的平方*/
	}
	for (i=1; i<=n; i++)
	{
		printf("%d*%d*%d = %d\n", i, i, i, i*i*i);/*输出所有数的立方*/
	}
	return 0;
}
