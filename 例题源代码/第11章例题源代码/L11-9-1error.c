#include <stdio.h>
char* GetStr(void);
int main(void)
{
	char *ptr = NULL;
	ptr = GetStr();
	puts(ptr);         /* 试图使用野指针 */
	return 0;
}
char* GetStr(void)
{
	char s[80];        /* 定义动态存储类型的数组 */
	scanf("%s", s);
	return s;           /* 试图返回动态局部变量的地址 */
}
