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
/* 函数功能：用字符指针作为函数参数，实现字符串拷贝 */
void  MyStrcpy(char *dstStr, char *srcStr)
{
	while (*srcStr != '\0')	/* 若当前srcStr所指字符不是字符串结束标志 */
	{
		*dstStr = *srcStr; 	/* 复制字符 */
		srcStr++;            	/* 使srcStr指向下一个字符 */
		dstStr++;            	/* 使dstStr指向下一个存储单元 */
	}
	*dstStr = '\0';         	/* 在字符串dstStr的末尾添加字符串结束标志 */
}
