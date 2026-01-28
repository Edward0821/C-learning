#include <stdio.h>
#define N 12
int main(void)
{
	char  name[N];
	printf("Enter your name:");
       scanf("%s", name);
	printf("Hello %s!\n",name);
	scanf("%s", name);          /* 读取输入缓冲区中余下的上次未被读走的字符 */
	printf("Hello %s!\n",name);
	return 0;
}
