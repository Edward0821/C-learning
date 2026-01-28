#include  <stdio.h>
#include  <string.h>
#define N 80           /*字符串最大长度*/
int main(void)
{
	int    n;
	char  str[N], min[N];
	printf("Input five countries' names:\n");
	gets(str);                          /*输入一个字符串*/
	strcpy(min, str);                  /*将其作为最小字符串保存*/
	for (n=1; n<5; n++)
	{
		gets(str);                     /*每次输入一个字符串*/
		if (strcmp(str, min) < 0)    /*比较两个字符串的大小,若str较小*/
		{
			strcpy(min, str);         /*则将字符串str复制给min*/
		}
	}
	printf("The minimum is:%s\n", min); /*输出最小字符串min*/
	return 0;
}
