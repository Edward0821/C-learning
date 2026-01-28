#include  <stdio.h>
union sample
{
	short  i;
	char   ch;
	float  f;
};                                /* 定义共用体类型union sample的模板 */
typedef union sample SAMPLE; /* 定义union sample的别名为SAMPLE */
int main(void)
{
	printf("bytes = %d\n", sizeof(SAMPLE));/*打印共用体类型所占内存字节数*/
	return 0;
}
