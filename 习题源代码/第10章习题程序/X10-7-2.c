#include <stdio.h>
#include <string.h>
#define N 80
void Inverse(char str[]);
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
void Inverse(char str[])
{
	int   len, i, j;
	char  temp;
	len = strlen(str);
	for (i=0, j=len-1; i<j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
