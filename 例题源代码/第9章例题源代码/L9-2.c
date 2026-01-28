#include <stdio.h>
int main(void)
{
	int  a = 0, b = 1;
	char c = 'A';
    int *pa, *pb;       /* 定义指针变量pa和pb */
    char *pc;            /* 定义指针变量pc */
    pa = &a;             /* 初始化指针变量pa使其指向a */
    pb = &b;             /* 初始化指针变量pb使其指向b */
    pc = &c;             /* 初始化指针变量pc使其指向c */
	printf("a is %d, &a is %p, pa is %p, &pa is %p\n", a, &a, pa, &pa);
	printf("b is %d, &b is %p, pb is %p, &pb is %p\n", b, &b, pb, &pb);
	printf("c is %c, &c is %p, pc is %p, &pc is %p\n", c, &c, pc, &pc);
	return 0;
}
