#include <stdio.h>
int main(void)
{
	char  ch;
	printf("Press a key and then press Enter:");
	ch = getchar();
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
	{
		printf("It is an English character!\n");
	}
	else if (ch <= '9' && ch >= '0')
	{
		printf("It is a digit character!\n");
	}
	else if (ch == ' ')
	{
		printf("It is a space character!\n");
	}
	else
	{
		printf("It is other character!\n");
	}
	return 0;
}
