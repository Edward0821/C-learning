#include <stdio.h>
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
	char *t1 = s, *t2 = s;
	for (; *t1!='\0'; t1++)
	{
		if (*t1 != c)
		{
			*t2 = *t1;
			t2++;
		}
	}
	*t2 = '\0';
}
