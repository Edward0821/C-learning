#include <stdio.h>
#include <stdlib.h>
void GetStr(char *);
int main(void)
{
	char *ptr = NULL;
	GetStr(ptr);
	puts(ptr);                /* 试图使用空指针 */
	return 0;
}
void GetStr(char *s)
{
	s = (char *)malloc(80); /* 申请动态分配的内存 */
	scanf("%s", s);
}
