#include <stdio.h>
#define  M   40
#define  N   11
int Mean(int answer[], int n);
int Median(int answer[], int n);
int Mode(int answer[], int n);
void DataSort(int a[], int n);
int main(void)
{
	int  i, feedback[M];
	printf("Input the feedbacks of 40 students:\n");
	for (i=0; i<M; i++)
	{
		scanf("%d", &feedback[i]);
	}
	printf("Mean value = %d\n", Mean(feedback, M));
	printf("Median value = %d\n", Median(feedback, M));
	printf("Mode value = %d\n", Mode(feedback, M));
	return 0;
}
/* 函数功能：若n>0则计算并返回n个数的平均数，否则返回-1 */
int Mean(int answer[], int n)
{
	int i, sum = 0;
	for (i=0; i<n; i++)
	{
		sum += answer[i];
	}
	return  n>0 ? sum/n : -1;
}
/* 函数功能：计算n个数的中位数 */
int Median(int answer[], int n)
{
	DataSort(answer, n);
	if (n%2 == 0)
		return  (answer[n/2] + answer[n/2-1]) / 2;
	else
		return  answer[n/2];
}
/* 函数功能：计算n个数的众数 */
int Mode(int answer[], int n)
{
	int  i, grade, max = 0, modeValue = 0, count[N] = {0};
	for (i=0; i<n; i++)
	{
		count[answer[i]]++;
	}
	for (grade=1; grade<=N-1; grade++)
	{
		if (count[grade] > max)
		{
			max = count[grade];
			modeValue = grade;
		}
	}
	return modeValue;
}
/*  函数功能：按选择法对数组a中的n个元素进行排序 */
void DataSort(int a[], int n)
{
	int i, j, k, temp;
	for (i=0; i<n-1; i++)
	{
		k = i;
		for (j=i+1; j<n; j++)
		{
			if (a[j] > a[k]) k = j;
		}
		if (k != i)
		{
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
}
