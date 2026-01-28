#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
void Insert(char *s);
int main(void)
{
	char str[N];
	printf("Input a string:");
	gets(str);
	Insert(str);
	printf("Insert results:%s\n", str);
	return 0;
}
void Insert(char *s)
{
	char str[N];
	char *t = str;
	strcpy(t, s);
	for (; *t!='\0'; s++,t++)
	{
		*s = *t;
		s++;
		*s = ' ';
	}
	*s = '\0';
}
