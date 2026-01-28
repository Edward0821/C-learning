#include  <stdio.h>
#include  <string.h>
#define N 80
int MinString(char str[][N], int n);
int main(void)
{
	int   n=5, min, i;
	char  str[5][N];
	printf("Input five countries' names:\n");
	for (i=0; i<n; i++)
	{
		gets(str[i]);
	}
	min = MinString(str, n);
	printf("The minimum is:%s\n", str[min]);
	return 0;
}
int MinString(char str[][N], int n)
{
	int i, minIndex;
	char min[N];
	strcpy(min, str[0]);
	minIndex = 0;
	for (i=1; i<n; i++)
	{
		if (strcmp(str[i], min) < 0)
		{
			strcpy(min, str[i]);
			minIndex = i;
		}
	}
	return minIndex;         /* 返回最小的字符串在二维字符数组中的位置 */
}
