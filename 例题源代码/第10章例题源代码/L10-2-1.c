#include <stdio.h>
#define N 12
int main(void)
{
	char  name[N];
	printf("Enter your name:");
    gets(name);
    printf("Hello %s!\n",name);
	return 0;
}
