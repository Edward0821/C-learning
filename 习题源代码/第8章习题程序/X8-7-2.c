#include <stdio.h>
#define  M  40
#define  N  11
int main(void)
{
	int  i, j, grade;
	int  feedback[M], count[N] = {0};
	printf("Input the feedbacks of 40 students:\n");
	for (i=0; i<M; i++)
	{
		scanf("%d", &feedback[i]);
	}
	for (i=0; i<M; i++)
	{
		count[feedback[i]] ++;
	}
	printf("Feedback\tCount\tHistogram\n");
	for (grade=1; grade<=N-1; grade++)
	{
		printf("%8d\t%5d\t", grade, count[grade]);
		for (j=0; j<count[grade]; j++)
		{
			printf("%c",'*');
		}
		printf("\n");
	}
	return 0;
}
