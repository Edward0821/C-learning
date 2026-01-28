#include  <stdio.h>
#include  <math.h>
#define ATHLETE	40           					/* 选手人数最高限 */
#define JUDGE 	     20           					/* 评委人数最高限 */
void  CountAthleteScore(int sh[], float sf[], int n, float f[], int m);
void  Sort(int h[], float f[], int n);
void  Print(int h[], float f[], int n);
void  CountJudgeScore(int ph[], float pf[], int m, float sf[], float f[],
					  int n);
int main(void)
{
	int  j, m, n;
	int  sh[ATHLETE];  							/* 选手的编号 */
	int  ph[JUDGE];   							/* 评委的编号 */
	float  sf[ATHLETE];  						/* 选手的最后得分 */
	float  pf[JUDGE];    						/* 评委的得分 */
	float  f[ATHLETE][JUDGE]; 					/* 评委给选手的评分 */
	printf("How many Athletes?");
	scanf("%d", &n);                      			/* 输入选手人数 */
	printf("How many judges?");
	scanf("%d", &m);                      			/* 输入评委人数 */
	for(j=1; j<=m; j++)
	{
		ph[j] = j;
	}
	printf("Scores of Athletes:\n");
	CountAthleteScore(sh, sf, n, *f, m); 		/* 现场为选手统计分数 */
	CountJudgeScore(ph, pf, m, sf, *f, n); 		/* 为各个评委打分 */
	printf("Order of Athletes:\n");
	Sort(sh, sf, n);                      			/* 选手得分排序 */
	Print(sh, sf, n);                     			/* 打印选手名次表 */
	printf("Order of judges:\n");
	Sort(ph, pf, m);                      			/* 评委得分排序 */
	Print(ph, pf, m);                     			/* 打印评委名次表 */
	printf("Over!Thank you!\n");
	return 0;
}
/* 函数功能：统计参赛选手的得分 */
void  CountAthleteScore(int sh[], float sf[], int n, float f[], int m)
{
	int  i, j;
	float  max, min;
	for (i=1; i<=n; i++)                         /* 第i个选手 */
	{
		printf("\nAthlete %d is playing.", i);
		printf("\nPlease enter his number code:");
		scanf("%d", &sh[i]);
		sf[i] = 0;
		max = 0;                                /* 最高分初值设为最小值 */
		min = 100;                              /* 最低分初值设为最大值 */
		for (j=1; j<=m; j++)                  /* 第j个评委 */
		{
			printf("Judge %d gives score:", j);
			scanf("%f", &f[i*m+j]);
			sf[i] = sf[i] + f[i*m+j];       /* 累加评委对第i个选手的评分 */
			if (max < f[i*m+j])              /* 找出最高分 */
				max = f[i*m+j];
			if (min > f[i*m+j])              /* 找出最低分 */
				min = f[i*m+j];
		}
		printf("Delete a maximum score:%.1f\n", max);
		printf("Delete a minimum score:%.1f\n", min);
		sf[i] = (sf[i] - max - min) / (m - 2); /*去掉一个最高分和最低分*/
		printf("The final score of Athlete %d is %.3f\n", sh[i], sf[i]);
	}
}
/* 函数功能：对分数从高到低排序 */
void Sort(int h[], float f[], int n)
{
	int  i, j, k, temp2;
	float  temp1;
	for (i=1; i<=n-1; i++)
	{
		k = i;
		for (j=i+1; j<=n; j++)
		{
			if (f[j] > f[k])  k = j;
		}
		if (k != i)
		{
			temp1 = f[k]; f[k] = f[i]; f[i] = temp1;
			temp2 = h[k]; h[k] = h[i]; h[i] = temp2;
		}
	}
}
/* 函数功能：打印名次表 */
void Print(int h[], float f[], int n)
{
	int  i;
	printf("order\tfinal score\tnumber code\n");
	for (i=1; i<=n; i++)
	{
		printf("%5d\t%11.3f\t%6d\n", i, f[i], h[i]);
	}
}
/* 函数功能：统计评委的得分 */
void CountJudgeScore(int ph[], float pf[], int m, float sf[], float f[],
					 int n)
{
	int  i, j;
	for (j=1; j<=m; j++)             /* 第j个评委 */
	{
		pf[j] = 0;
		for (i=1; i<=n; i++)        /* 第i个选手 */
		{
			pf[j] = pf[j] + (f[i*m+j] - sf[i]) * (f[i*m+j] - sf[i]);
		}
		pf[j] = 10 - sqrt(pf[j]/n);
	}
}
