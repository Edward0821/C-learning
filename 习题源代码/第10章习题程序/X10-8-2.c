#include <stdio.h>
#include <string.h>
#define N 80
void MyStrcat(char dstStr[], char srcStr[]);
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
void  MyStrcat(char dstStr[], char srcStr[])
{
	int  i=0, j=0;
	while (dstStr[i] != '\0') /* 将下标移动到字符串dstStr的末尾 */
	{
		i++;
	}
	while (srcStr[j] != '\0')
	{
		dstStr[i] = srcStr[j];
		i++;
		j++;
	}
	dstStr[i] = '\0';		/* 在字符串dstStr的末尾添加一个字符串结束标志 */
}
