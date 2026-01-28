#include <stdio.h>
int main(void)
{
	char  ch;
	printf("Press a key and then press Enter:");
	ch = getchar();
	if (ch >= 'A' && ch <= 'Z')
	{
		ch = ch + 32;
	}
	if (ch >= 'a' && ch <= 'z')
	{
		ch = ch - 32;
	}
	printf("%c, %d\n", ch, ch);
	return 0;
}
