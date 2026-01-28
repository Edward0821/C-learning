#include <stdio.h>
#include <string.h>
#define N 80
void Inverse(char *pStr);
int main(void)
{
	char a[N];
   	printf("Input a string:");
	gets(a);
	Inverse(a);
	printf("Inversed results:%s\n", a);
	return 0;
}
/* 函数功能： 实现将字符数组中的字符串逆序存放 */
void Inverse(char *pStr)
{
	int  len;
	char temp;
	char *pStart;			/* 指针变量pStart指向字符串的第一个字符 */
	char *pEnd;			/* 指针变量pEnd指向字符串的最后一个字符 */
	len = strlen(pStr);	/* 求出字符串长度 */
	for (pStart=pStr,pEnd=pStr+len-1; pStart<pEnd; pStart++,pEnd--)
	{
		temp = *pStart;
		*pStart = *pEnd;
		*pEnd = temp;
	}
}
