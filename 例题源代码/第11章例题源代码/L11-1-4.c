#include <stdio.h>
int main(void)
{
	int  a[5], *p = NULL, i;
	printf("Input five numbers:");
	p = a;                      /* p=a等价于p=&a[0] */
	for (i=0; i<5; i++)
	{
		scanf("%d", &p[i]); /* &p[i]等价于p+i */
	}
	p = a;   			             /* 在再次循环开始前，确保指针P指向数组首地址 */
	for (i=0; i<5; i++)
	{
		printf("%4d", p[i]); /* p[i]等价于*(p+i) */
	}
	printf("\n");
	return 0;
}
