#include <stdio.h>
void GetStr(char *);
int main(void)
{
	char *ptr = NULL; /* 指针变量初始化为空指针 */
	GetStr(ptr);
	puts(ptr);          /* 试图使用空指针 */
	return 0;
}
void GetStr(char *s)    /* 指针形参接收实参传过来的是空指针 */
{
	scanf("%s", s);    /* 试图使用空指针 */
}
