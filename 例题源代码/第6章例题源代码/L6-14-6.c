#include <stdio.h>
int main(void)
{
	int  x = 0;       /* 因do-while循环中先对x加1，故这里x初始化为0 */
	do{
	   x++;
	}while (!(x%5==1 && x%6==5 && x%7==4 && x%11==10));
	printf("x = %d\n", x);
	return 0;
}
