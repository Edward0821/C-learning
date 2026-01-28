#include <stdio.h>
#include <string.h>
#define N 80
void Inverse(char str[], char ptr[]);
int main(void)
{
	char a[N], b[N];
   	printf("Input a string:");
	gets(a);
	Inverse(a, b);
	printf("Inversed results:%s\n", b);
	return 0;
}
/* 函数功能： 实现将字符数组中的字符串逆序存放 */
void Inverse(char str[], char ptr[])
{
	int   len, i, j;
	len = strlen(str);
	for (i=0, j=len-1; str[i] != '\0'; i++, j--)
   	{
       	ptr[j] = str[i];
   	}
   	ptr[i]='\0';
}
