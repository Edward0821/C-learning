#include <stdio.h>
long Fib(int a);
int count;     /*全局变量count用于累计递归函数被调用的次数，自动初始化为0*/
int main(void)
{
	   int n, i, x;
	   printf("Input n:");
	   scanf("%d", &n);
	   for (i=1; i<=n; i++)
	   {
		   count = 0;   /* 计算下一项Fibonacci数列时将计数器count清零 */
		   x = Fib(i);
		   printf("Fib(%d)=%d, count=%d\n", i, x, count);
	   }
	   return 0;
}
/* 函数功能：用递归法计算Fibonacci数列中的第n项的值 */
long Fib(int n)
{
	count++;	  /* 累计递归函数被调用的次数，记录于全局变量count中 */
	if (n == 0)         return 0;          /* 基线情况 */
	else if (n == 1)   return 1;          /* 基线情况 */
	else   return (Fib(n-1) + Fib(n-2)); /* 一般情况 */

}
