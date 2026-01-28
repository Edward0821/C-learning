#include <stdio.h>
#include <string.h>
#define N 1024
int main(int argc, char *argv[])
{
	char buffer[N];
	if (argc > 1)
	{
		strcpy(buffer, argv[1]);
	}
	return 0;
}
