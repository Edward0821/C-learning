#include <stdio.h>
#include <string.h>
#define N 80
void  MyStrcat(char *dstStr, char *srcStr);
int main(void)
{
	char  s[N], t[N];
	printf("Input a string:");
	gets(s);
	printf("Input another string:");
	gets(t);
	MyStrcat(s,t);
	printf("Concatenate results:%s\n", s);
	return 0;
}
/*  函数功能：将字符串srcStr连接到字符串dstStr之后 */
void  MyStrcat(char *dstStr, char * srcStr)
{
	while (*dstStr != '\0')
	{
		dstStr++;
	}
	while (*srcStr != '\0')/* 若srcStr所指字符不是字符串结束标志 */
	{
		*dstStr = * srcStr;	/* 将srcStr所指字符复制到dstStr所指的内存中 */
		srcStr++;			/* 使srcStr指向下一个字符 */
		dstStr++;			/* 使dstStr指向下一个存储单元 */
	}
	*dstStr = '\0';			/* 在字符串dstStr的末尾添加字符串结束标志 */
}
