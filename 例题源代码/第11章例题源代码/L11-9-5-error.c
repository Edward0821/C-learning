#include <stdio.h>
void GetStr(char *);
int main(void)
{
	char *ptr = NULL; /* 指针变量初始化为空指针 */
	GetStr(ptr);
	if (ptr != NULL)
	{
		puts(ptr);
	}
	else                   /* 一旦指针为空指针，则输出"使用空指针"的提示 */
	{
		printf("Null pointer is used!\n");
	}
	return 0;
}
void GetStr(char *s)    /* 指针形参接收实参传过来的是空指针 */
{
	if (s != NULL)
	{
		scanf("%s", s);
	}
	else                  /* 一旦指针为空指针，则输出"使用空指针"的提示 */
	{
		printf("Null pointer is used!\n");
	}
}
