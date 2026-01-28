#include <stdio.h>
#define N 12
int main(void)
{
	char  name[N];
	printf("Enter your name:");
    fgets(name, sizeof(name), stdin); /* 限制输入字符串长度不超过数组大小 */
    printf("Hello %s!\n",name);
	return 0;
}
