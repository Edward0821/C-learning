#include <stdio.h>
#include <string.h>
#define N 100
void Insert(char s[]);
int main(void)
{
	char str[N];
	printf("Input a string:");
	gets(str);
	Insert(str);
	printf("Insert results: %s\n", str);
	return 0;
}
void Insert(char s[])
{
	char t[N];
	int  i, j;
	strcpy(t, s);
	for (i=0,j=0; t[i]!='\0'; i++,j++)
	{
		s[j] = t[i];
		j++;
		s[j] = ' ';
	}
	s[j] = '\0';
}
