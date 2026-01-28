#include <stdio.h>
int CountWords(char str[]);
int main(void)
{
	char  str[20];
    printf("Input a string:");
	gets(str);
	printf("Numbers of words = %d\n", CountWords(str));
	return 0;
}
int CountWords(char str[])
{
	int    i, num;
    num = str[0] != ' ' ? 1 : 0;
	for (i=1; str[i]!='\0'; i++)
	{
		if (str[i]!=' ' && str[i-1] == ' ')
		{
			num++;
		}
	}
	return num;
}

