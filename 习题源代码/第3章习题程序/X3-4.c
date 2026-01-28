#include  <math.h>
#include  <stdio.h>
int main(void)
{
	float  a, b, c, disc, x1, x2, p, q;
	printf("Please enter the coefficients a,b,c:"); /*显示提示信息*/
	scanf("%f,%f,%f", &a, &b, &c);	/* 输入a,b,c的值*/
	disc = b * b - 4 * a * c;      	/*计算判别式*/
	p = - b / (2 * a);
	q = sqrt(disc) / (2 * a);
	x1 = p + q;                      	/*计算实根x1*/
	x2 = p - q;                   		/*计算实根x2*/
	printf("x1=%7.4f, x2=%7.4f\n", x1, x2);    /*输出x1和x2*/
	return 0;
}
