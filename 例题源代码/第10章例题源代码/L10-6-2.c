#include  <stdio.h>
unsigned int  MyStrlen(const char *pStr);
int main(void)
{
	char   a[80];
	printf("Input a string:");
	gets(a);
	printf("The length of the string is: %u\n", MyStrlen(a));
	return 0;
}
/* 函数功能：用字符指针作函数参数，计算字符串的长度 */
unsigned int  MyStrlen(const char *pStr)
{
	unsigned int  len = 0;   /* 计数器置0 */
	for ( ; *pStr!='\0'; pStr++)
	{
		len++;                 /* 利用循环统计不包括'\0'在内的字符个数 */
	}
	return len;             /* 返回实际字符个数 */
}
