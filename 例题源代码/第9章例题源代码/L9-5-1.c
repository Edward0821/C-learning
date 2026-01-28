#include <stdio.h>
void Fun(int *par);
int main(void)
{
	int arg = 1 ;
	printf("arg = %d\n", arg);
	Fun(&arg);                            /* 传递变量arg的地址值给函数 */
	printf("arg = %d\n", arg);
	return 0;
}
void Fun(int *par)
{
	printf("par = %d\n", *par);       /* 输出形参指向的变量的值 */
	*par = 2;                             /* 改变形参指向的变量的值 */
}
