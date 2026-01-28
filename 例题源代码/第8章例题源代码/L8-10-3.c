#include <stdio.h>
#define N 40
int ReadScore(int score[], long num[]);          /*ReadScore()函数原型*/
int BinSearch(long num[], long x, int n);        /*BinSearch()原函数型*/
void DataSort(int score[], long num[], int n);   /*DataSort()函数原型*/
void PrintScore(int score[], long num[], int n); /*PrintScore()函数原型*/

int main(void)
{
	int score[N], n, pos;
	long num[N],x;
	n = ReadScore(score, num);  /* 输入成绩和学号，返回学生总数 */
	printf("Total students are %d\n",n);
	DataSort(score, num, n);
	printf("Sorted scores:\n");
	PrintScore(score, num, n); /* 输出成绩排序结果 */
	printf("Input the searching ID:");
	scanf("%ld", &x);          	 /*以长整型格式从键盘输入待查找的学号x*/
	pos = BinSearch(num, x, n); /* 查找学号为num的学生 */
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
/*按折半查找法查找值为x的数组元素，若找到则返回x在数组中的下标位置，否则返回-1*/
int BinSearch(long num[], long x, int n) /*BinSearch()函数定义*/
{
	int  low, high, mid;
	int pos = -1;           	/* 若循环结束仍未找到，则返回pos的初始值-1 */
	int find = 0;           	/* 置找到标志变量flag为假 */
	low = 0;                     /* 区间左端点置为0 */
	high = n - 1;            	/* 区间右端点置为n-1 */
	while (!find && low <= high)  /* 若左端点小于等于右端点，则继续查找 */
	{
		mid = (high + low) / 2;  /* 取数据区间的中点 */
		if (x > num[mid])
		{
			low = mid + 1;       /* 若x>num[mid]，则修改区间的左端点 */
		}
		else  if (x < num[mid])
		{
			high = mid - 1; 	/* 若x<num[mid]，则修改区间的右端点 */
		}
		else
		{
			pos = mid;           /* 若找到，则置下标值为mid */
			find = 1;            /* 置找到标志变量flag为真 */
		}
	}
	return pos;
}
/* 函数功能：按选择法将数组num的元素值按从小到大排序 */
void DataSort(int score[], long num[], int n) /*DataSort()函数定义*/
{
	int i, j, k, temp1;
	long temp2;
	for (i=0; i<n-1; i++)
	{
		k = i;
		for (j=i+1; j<n; j++)
		{
			if (num[j] < num[k])     /* 按数组num的元素值从小到大排序 */
			{
				k = j;                 /* 记录最大数下标位置 */
			}
		}
		if (k != i)                  /* 若最大数不在下标位置i */
		{
			/* 交换成绩 */
			temp1 = score[k]; score[k] = score[i];  score[i] = temp1;
			/* 交换学号 */
			temp2 = num[k]; num[k] = num[i];  num[i] = temp2;
		}
	}
}
/*函数功能： 打印学生学号和成绩*/
void PrintScore(int score[], long num[], int n) /*PrintScore()函数定义*/
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%10ld%4d\n", num[i], score[i]); /*以长整型格式输入学号*/
	}
}
