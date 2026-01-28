#include <stdio.h>
#define  CURRENT  100
int main(void)
{
	int      year;                        	/* 产值翻番所需年数 */
	double  growRate; 	                   /* 工业产值的增长率 */
	double  output;                   		/* 工业总产值 */
	printf("Input grow rate:");
	scanf("%lf", &growRate);
	output = CURRENT;        	     /* 当年产值为100万元 */
	for (year=0; output<2*CURRENT; year++)
	{
		output = output * (1 + growRate);
	}
	printf("When grow rate is %.0f%%, the output can be doubled after %d years.\n", growRate*100, year);
	return 0;
}
