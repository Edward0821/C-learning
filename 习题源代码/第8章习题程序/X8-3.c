#include  <stdio.h>
#define N 40
int	GetFailNum(int score[], int n);
int main(void)
{
	int i, n, fail, score[N];
	printf("How many students?");
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &score[i]);
	}
	fail = GetFailNum(score, n);
	printf("Fail students = %d\n", fail);
	return 0;
}
/* 函数功能：统计不及格人数 */
int GetFailNum(int score[], int n)
{
	int  i, count = 0;
	for (i=0; i<n; i++)
	{
		if (score[i] < 60)  count++;
	}
	return count;
}
