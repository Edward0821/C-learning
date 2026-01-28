#include <stdio.h>
#define N 40
int ReadScore(int score[], long num[]);          /*ReadScore()函数原型*/
int LinSearch(long num[], long x, int n);        /* LinSearch()原函数型*/
int main(void)
{
	int score[N], n, pos;
	long num[N], x;
	n = ReadScore(score, num);  /* 输入成绩和学号，返回学生总数 */
	printf("Total students are %d\n", n);
	printf("Input the searching ID:");
	scanf("%ld", &x);          	 /* 以长整型格式从键盘输入待查找的学号x */
	pos = LinSearch(num, x, n); /* 查找学号为num的学生 */
	if (pos != -1)              	 /* 若找到，则打印其分数 */
	{
		printf("score = %d\n", score[pos]);
	}
	else                      		/* 若未找到，则打印"未找到"提示信息*/
	{
		printf("Not found!\n");
	}
	return 0;
}
/* 函数功能：输入学生的学号及其某门课成绩，当输入负值时，结束输入，返回学生人数 */
int ReadScore(int score[], long num[]) /* ReadScore()函数定义 */
{
	int i = -1;         /*i初始化为-1，循环体内增1后可保证数组下标从0开始*/
	do{
		i++;
		printf("Input student's ID and score:");
		scanf("%ld%d", &num[i], &score[i]);
	} while (num[i] >0 && score[i] >= 0); /* 输入负值时结束成绩输入 */
	return i;                                   /* 返回学生总数 */
}
/*按线性查找法查找值为x的数组元素，若找到则返回x在数组中的下标位置，否则返回-1*/
int LinSearch(long num[], long x, int n) /* LinSearch()函数定义 */
{
	int  i;
	for (i=0; i<n; i++)
	{
		if (num[i] == x)	return i; /* 若找到则返回x在数组中的下标 */
	}
	return (-1);                           /* 若循环结束仍未找到，则返回-1 */
}
