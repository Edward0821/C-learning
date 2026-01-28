#include <stdio.h>
int main(void)
{
	int  a = 0, b = 1;
	char c = 'A';
    int *pa, *pb;        /* 定义了可以指向整型数据的指针变量pa和pb */
    char *pc;             /* 定义了可以指向字符型数据的指针变量pc */
	printf("a is %d, &a is %p, pa is %p\n", a, &a, pa);
	printf("b is %d, &b is %p, pb is %p \n", b, &b, pb);
	printf("c is %c, &c is %p, pc is %p \n", c, &c, pc);
	return 0;
}
