#include <stdio.h>
#define N 12
int main(void)
{
	char  name[N];
	char  *ptrName = name;  /* 声明了一个指向数组name的字符指针ptrName */
	printf("Enter your name:");
	gets(ptrName);           /* 输入字符串存入字符指针ptrName所指向的内存 */
    printf("Hello %s!\n", ptrName);
	return 0;
}
