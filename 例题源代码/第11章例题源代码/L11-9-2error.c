#include <stdio.h>
char* GetStr(void);
int main(void)
{
	char *ptr = NULL;
	printf("ptr = %p\n", ptr);/* 打印初始化为NULL后的指针变量的值 */
	printf("Input a string:");
	ptr = GetStr();
	printf("ptr = %p\n", ptr);/* 打印函数返回后在栈上创建的内存的首地址 */
	puts(ptr);                    /* 试图使用野指针，将导致程序输出乱码 */
	return 0;
}
char* GetStr(void)
{
	char s[80];                  /* 定义动态存储类型的数组 */
	scanf("%s", s);
	printf("s = %p\n", s);    /* 打印函数返回前在栈上创建的内存的首地址 */
	return s;                    /* 试图返回动态局部变量的地址 */
}
