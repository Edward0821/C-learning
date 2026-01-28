#include <stdio.h>
#include <stdlib.h>
char* GetStr(char *s);
int main(void)
{
	char *ptr = NULL;
	ptr = GetStr(ptr);      /* 使ptr指向动态分配的内存的首地址 */
	puts(ptr);
	free(ptr);                /* 释放ptr指向的动态分配的内存 */
	return 0;
}
char* GetStr(char *s)
{
	s = (char *)malloc(80); /* 申请动态分配的内存 */
	scanf("%s", s);
	return s;                  /* 返回动态分配的内存的首地址 */
}
