#include <stdio.h>
int Gcd(int a, int b);
int main(void)
{
	int a, b, c;
	printf("Input a,b:");
	scanf("%d,%d",&a, &b);
	c = Gcd(a,b);
	if (c != -1)
	{
		printf("Greatest Common Divisor of %d and %d is %d\n", a, b, c);
	}
	else
	{
		printf("Input number should be positive!\n");
	}
	return 0;
}
/* 函数功能：递归方法计算a和b的最大公约数，输入负数时返回-1 */
int Gcd(int a, int b)
{
    if (a <=0 || b <=0)
    {
		return -1;
    }
    if (a == b)
    {
        return a;
    }
    else if (a > b)
    {
        return Gcd(a-b, b);
    }
    else
    {
        return Gcd(a, b-a);
    }
}
