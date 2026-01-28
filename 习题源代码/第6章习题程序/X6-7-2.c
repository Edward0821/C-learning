#include <stdio.h>
#define  CURRENT  100
int main(void)
{
	int      year = 0;            /* 产值翻番所需年数，初始化为0 */
	double  growRate; 	          /* 工业产值的增长率 */
	double  output = CURRENT;   /* 工业总产值，初始化为当年产值100万元*/
	printf("Input grow rate:");
	scanf("%lf", &growRate);
	do {
		output = output * (1 + growRate);
		year++;
	}while (output < 2*CURRENT);
	printf("When grow rate is %.0f%%, the output can be doubled after %d years.\n", growRate*100, year);
	return 0;
}
