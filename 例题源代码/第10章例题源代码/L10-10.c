#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char str[] = {"   123.5"};
	int intNum;
	long longNum;
	double doubleNum;
	intNum = atoi(str);      /* 字符串转换为整型数 */
	longNum = atol(str);     /* 字符串转换为长整型数 */
	doubleNum = atof(str);   /* 字符串转换为双精度实型数 */
	printf("intNum = %d\n", intNum);
	printf("longNum = %ld\n", longNum);
	printf("doubleNum = %f\n", doubleNum);
	return 0;
}
