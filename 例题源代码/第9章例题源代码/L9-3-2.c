#include <stdio.h>
int main(void)
{
	int  a = 0, b = 1;
	char c = 'A';
    int *pa = &a, *pb = &b; /* 在定义指针变量pa和pb的同时对其初始化 */
    char *pc = &c;            /* 在定义指针变量pc的同时对其初始化 */
    *pa = 9;                   /* 修改指针变量pa所指向的变量的值 */
	printf("a is %d, &a is %p, pa is %p, *pa is %d\n", a, &a, pa, *pa);
	printf("b is %d, &b is %p, pb is %p, *pb is %d\n", b, &b, pb, *pb);
	printf("c is %c, &c is %p, pc is %p, *pc is %c\n", c, &c, pc, *pc);
	return 0;
}
