#include  <math.h>
#include  <stdio.h>
int main(void)
{
	int n;					/* 存款期变量声明 */
	double rate;		/* 存款年利率变量声明 */
	double capital;		/* 存款本金变量声明 */
	double deposit;		/* 本利之和变量声明 */
	printf("Please enter rate, year, capital:");
	scanf("%lf,%d,%lf", &rate, &n, &capital);
	deposit = capital * pow(1+rate, n); /* 计算存款利率之和 */
	printf("deposit = %f\n", deposit); /* 打印存款利率之和 */
	return 0;
}
