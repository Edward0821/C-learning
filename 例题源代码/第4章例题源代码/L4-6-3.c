#include <stdio.h>
int main(void)
{
	int    a;
	char  b;
	float  c;
	printf("Please input an integer:");
	scanf("%d", &a);
	printf("integer: %d\n", a);
	printf("Please input a character:");
	scanf(" %c", &b); /*在%c前面加一个空格，将存于缓冲区中的回车符读入*/
	printf("character: %c\n", b);
	printf("Please input a float number:");
	scanf("%f", &c);
	printf("float: %f\n", c);
	return 0;
}
