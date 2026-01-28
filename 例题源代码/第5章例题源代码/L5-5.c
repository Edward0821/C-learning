#include  <stdio.h>
int main(void)
{
	int    data1, data2;
	char  op;
	printf("Please enter an expression:");
	scanf("%d%c%d", &data1, &op, &data2);  /* 输入运算表达式 */
	switch (op)                        /* 根据输入的运算符确定执行的运算 */
	{
	case '+':                         /* 加法运算 */
		printf("%d + %d = %d \n", data1, data2, data1 + data2);
		break;
	case '-':                         /* 减法运算 */
		printf("%d - %d = %d \n", data1, data2, data1 - data2);
		break;
	case '*':                         /* 乘法运算 */
		printf("%d * %d = %d \n", data1, data2, data1 * data2);
		break;
	case '/':                         /* 除法运算 */
		if (0 == data2)         /* 为避免除0错误，检验除数是否为0 */
			printf("Division by zero!\n");
		else
			printf("%d / %d = %d \n", data1, data2, data1 / data2);
		break;
	default:                          /* 处理非法运算符 */
		printf("Invalid operator! \n");
	}
	return 0;
}
