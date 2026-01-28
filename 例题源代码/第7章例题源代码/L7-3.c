#include <stdio.h>
unsigned long  Fact(unsigned int  n);
int main(void)
{
	int  m;
	do{
		printf("Input m(m>0):");
		scanf("%d", &m);
	}while (m<0);	    /* 增加对输入数据的限制，确保输入的数据为无符号整数 */
	printf("%d! = %lu\n", m, Fact(m)); /* 无符号长整型格式输出阶乘值 */
	return 0;
}
/*函数功能：用迭代法计算无符号整型变量n的阶乘，当n>=0时返回n!；否则返回-1 */
unsigned long  Fact(unsigned int  n)
{
	unsigned int  i;
    unsigned long result = 1;
    for (i=2; i<=n; i++)
		result *= i;
    return result;
}
