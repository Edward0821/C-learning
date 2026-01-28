#include <stdio.h>
#include <ctype.h>
#define N 80
int main(void)
{
	char name[N];
	int i;
	printf("Input a name:");
	gets(name);                    /* 输入名和姓 */
	name[0] = toupper(name[0]); /* 将名的首字母变为大写 */
	i = 1;
	while (!isspace(name[i]))    /* 跳过所有字母，直到遇空格为止 */
	{
		i++;
	}
	while (!isalpha(name[i]))    /* 跳过所有空格，直到遇字母为止 */
	{
		i++;
	}
	name[i] = toupper(name[i]); /* 将姓的首字母变为大写 */
	printf("Formatted Name:%s\n", name);
	return 0;
}
