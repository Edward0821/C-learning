#include <stdio.h>
int main(void)
{
    int a = 1, c = 2, b[5] = {0}, i;
    printf("%p, %p, %p\n", b, &c, &a);/* 打印数组b、变量c和a的首地址 */
    for (i=0; i<=8; i++)                /* 让下标值越界访问数组的元素 */
    {
		b[i] = i;
		printf("%d  ", b[i]);
    }
	printf("\nc=%d, a=%d, i=%d\n", c, a, i);
	return 0;
}
