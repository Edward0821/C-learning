#include <stdio.h>
int main(void)
{
	int  a[5], i;
	printf("Input five numbers:");
	for (i=0; i<5; i++)
	{
		scanf("%d", &a[i]);    /* 用下标法引用数组元素 */
	}
	for (i=0; i<5; i++)
	{
		printf("%4d", a[i]);   /* 用下标法引用数组元素 */
	}
	printf("\n");
	return 0;
}
