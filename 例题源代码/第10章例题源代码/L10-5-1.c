#include  <stdio.h>
#define N 80
void  MyStrcpy(char dstStr[], char srcStr[]);
int main(void)
{
	char  a[N], b[N];
	printf("Input a string:");
	gets(a);                      /* 输入字符串 */
	MyStrcpy(b, a);              /* 将字符数组a中的字符串拷贝到b中 */
	printf("The copy is:");
	puts(b);                       /* 输出复制后的字符串 */
	return 0;
}
/* 函数功能：用字符数组作为函数参数实现字符串拷贝 */
void  MyStrcpy(char dstStr[], char srcStr[])
{
	int  i = 0;                   /* 数组下标初始化为0 */
	while (srcStr[i] != '\0')  /* 若当前取出的字符不是字符串结束标志 */
	{
		dstStr[i] = srcStr[i];/* 复制字符 */
		i++;                      /* 移动下标 */
	}
	dstStr[i] = '\0';            /* 在字符串dstStr的末尾添加字符串结束标志 */
}
