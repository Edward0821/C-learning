#include <stdio.h>
void  Squeeze(char s[], char c);
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
void  Squeeze(char s[], char c)
{
	int i,j;
	for (i=j=0; s[i]!='\0'; i++)
	{
		if (s[i] != c)
		{
			s[j] = s[i];
			j++;
		}
	}
	s[j] = '\0';
}
