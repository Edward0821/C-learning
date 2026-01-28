#include <stdio.h>
#define  M   40
#define  N   11
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
		switch (feedback[i])
		{
				case 1:	count[1]++;
						break;
				case 2:	count[2]++;
						break;
				case 3:	count[3]++;
						break;
				case 4:	count[4]++;
						break;
				case 5:	count[5]++;
						break;
				case 6:	count[6]++;
						break;
				case 7:	count[7]++;
						break;
				case 8:	count[8]++;
						break;
				case 9:	count[9]++;
						break;
				case 10:count[10]++;
						break;
				default:printf("input error!\n");
						break;
		}
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
