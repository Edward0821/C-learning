#include <stdio.h>
int main(void)
{
	int  a = 0, b = 1;
	char c = 'A';
    int *pa = NULL, *pb = NULL; /* 定义指针变量并用NULL对其初始化 */
    char *pc = NULL;              /* 定义指针变量并用NULL对其初始化 */
	printf("a is %d, &a is %p, pa is %p\n", a, &a, pa);
	printf("b is %d, &b is %p, pb is %p \n", b, &b, pb);
	printf("c is %c, &c is %p, pc is %p \n", c, &c, pc);
	return 0;
}
