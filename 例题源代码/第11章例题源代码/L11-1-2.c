#include <stdio.h>
int main(void)
{
	int  a[5], i;
	printf("Input five numbers:");
	for (i=0; i<5; i++)
	{
		scanf("%d", a+i);       /* 这里a+i等价于&a[i] */
	}
	for (i=0; i<5; i++)
	{
		printf("%4d", *(a+i)); /* 这里*(a+i)等价于a[i] */
	}
	printf("\n");
	return 0;
}
