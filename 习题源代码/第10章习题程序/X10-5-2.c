#include <stdio.h>
#include <string.h>
#define N 100
void  Squeeze(char *s, char c);
int main(void)
{
	char  str[20], ch;
    printf("Input a string:");
	gets(str);
	printf("Input a character:");
	ch = getchar();
	Squeeze(str, ch);
	printf("Results: %s\n", str);
	return 0;
}
void  Squeeze(char *s, char c)
{
	char str[N];
	char *t = str;
	strcpy(t, s);
	for (; *t!='\0'; t++)
	{
		if (*t != c)
		{
			*s = *t;
			s++;
		}
	}
	*s = '\0';   /* 在字符串t2的末尾添加一个字符串结束标志 */
}
