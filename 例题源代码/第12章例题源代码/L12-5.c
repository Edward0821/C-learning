#include  <stdio.h>
struct date
{
    int year;
    int month;
    int day;
};
void Func(struct date *pt)  /* 结构体指针变量作函数形参 */
{
	pt->year = 2000;
	pt->month = 5;
	pt->day = 22;
}
int main(void)
{
	struct date d;
	d.year = 1999;
	d.month = 4;
	d.day = 23;
	printf("Before function call:%d/%02d/%02d\n", d.year, d.month, d.day);
	Func(&d);              /* 结构体变量的地址作函数实参，传地址调用 */
	printf("After function call:%d/%02d/%02d\n", d.year, d.month, d.day);
	return 0;
}
