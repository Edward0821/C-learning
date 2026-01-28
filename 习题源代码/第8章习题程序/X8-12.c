#include <stdio.h>
#define N 12
void Fibonacci(int f[], int n);
int main(void)
{
	int  f[N], i;
	Fibonacci(f, N);
	printf("\nTotal = %d\n", f[N-1]);
	return 0;
}
/* 函数功能：计算并打印Fibonacci数列的前n项 */
void Fibonacci(int f[], int n)
{
	int  i;
	f[0] = 1;
	f[1] = 2;
	for (i=2; i<n; i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	for (i=0; i<N; i++)
	{
		printf("%4d", f[i]);
	}
}
