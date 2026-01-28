#include  <stdio.h>
typedef struct sample
{
	char  m1;
	int   m2;
	char  m3;
}SAMPLE;                         /* 定义结构体类型SAMPLE */
int main(void)
{
	SAMPLE s = {'a', 2, 'b'};		/* 定义结构体变量s并对其进行初始化 */
	printf("bytes = %d\n", sizeof(s));/* 打印结构体变量s所占内存字节数 */
	return 0;
}
