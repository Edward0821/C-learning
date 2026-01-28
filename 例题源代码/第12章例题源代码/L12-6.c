#include  <stdio.h>
struct date
{
    int year;
    int month;
    int day;
};
struct date Func(struct date p)  /* 函数的返回值为结构体类型 */
{
	p.year = 2000;
	p.month = 5;
	p.day = 22;
	return p;                        /* 从函数返回结构体变量的值 */
}
int main(void)
{
	struct date d;
	d.year = 1999;
	d.month = 4;
	d.day = 23;
	printf("Before function call:%d/%02d/%02d\n", d.year, d.month, d.day);
	d = Func(d);              /* 函数返回值为结构体变量的值 */
	printf("After function call:%d/%02d/%02d\n", d.year, d.month, d.day);
	return 0;
}
