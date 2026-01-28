#include  <stdio.h>
int main(void)
{
	int a, b, max, ret;
	printf("Input a, b:");
	ret = scanf("%d,%d",&a, &b); /* 记录scanf函数的返回值 */
	if (ret != 2)  /* 根据scanf函数返回值,判断输入数据个数或者格式是否错误 */
	{
		printf("Input data quantity or format error!\n");
		while(getchar() != '\n');  /* 清除输入缓冲区中的错误数据 */
	}
	else             /* 此处可以是正确读入数据后应该执行的操作 */
	{
		max = a > b ? a : b;
		printf("max = %d\n", max);
	}
	return 0;
}
