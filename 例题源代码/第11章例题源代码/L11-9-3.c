#include <stdio.h>
void GetStr(char *);
int main(void)
{
	char s[80];
	char *ptr = s;      /* 指针初始化，使其指向数组s的首地址 */
	GetStr(ptr);
	puts(ptr);           /* 将用户输入的字符串正确地显示输出 */
	return 0;
}
void GetStr(char *s)     /* 指针形参接收实参传过来的数组首地址 */
{
	scanf("%s", s);
}
