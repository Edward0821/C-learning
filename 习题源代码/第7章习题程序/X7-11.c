#include <stdio.h>
void Hanoi(int n, char a, char b, char c);
void Move(int n, char a, char b);
int main(void)
{
	int n;
	printf("Input the number of disks:");
	scanf("%d", &n);
	printf("Steps of moving %d disks from A to B by means of C:\n", n);
	Hanoi(n, 'A', 'B', 'C'); /*调用递归函数Hanoi()将n个圆盘借助于C由A移到B*/
	return 0;
}
/* 函数功能：用递归方法将n个圆盘借助c从a移到b */
void Hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		Move(n, a, b);	     /* 将第n个圆盘由a移到b */
	}
	else
	{
		Hanoi(n-1, a, c, b); /* 递归调用Hanoi()，将第n-1个圆盘借助b由a移到c */
		Move(n, a, b); 	     /* 第n个圆盘由a移到b */
		Hanoi(n-1, c, b, a); /*递归调用Hanoi()，将第n-1个圆盘借助a由c移到b */
	}
}
/* 函数功能：将第n个圆盘从a移到b */
void Move(int n, char a, char b)
{
	printf("Move %d: from %c to %c\n", n, a, b);
}
