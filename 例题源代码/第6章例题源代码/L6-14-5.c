#include <stdio.h>
int main(void)
{
	int  x = 0;       /* 因do-while循环中先对x加1，故这里x初始化为0 */
	int  find = 0;   /* 标志变量初值置为假 */
	do{
		x++;
		find = (x%5==1 && x%6==5 && x%7==4 && x%11==10);
	}while (!find);
	printf("x = %d\n", x);
	return 0;
}
