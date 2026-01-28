#include  <math.h>
#include  <stdio.h>
int main(void)
{
	float  data1, data2;
	char   op;
	printf("Please enter the expression:\n");
	scanf("%f %c%f", &data1, &op, &data2);  /* %c前有一个空格 */
	switch (op)
	{
	case '+':
		printf("%f + %f = %f \n", data1, data2, data1 + data2);
		break;
	case '-':
		printf("%f - %f = %f \n", data1, data2, data1 - data2);
		break;
	case '*':
	case 'x':
	case 'X':
		printf("%f * %f = %f \n", data1, data2, data1 * data2);
		break;
	case '/':
		if (fabs(data2) <= 1e-7)		/* 实数与0比较 */
			printf("Division by zero!\n");
		else
			printf("%f / %f = %f \n", data1, data2, data1 / data2);
		break;
	default:
		printf("Invalid operator! \n");
	}
	return 0;
}
