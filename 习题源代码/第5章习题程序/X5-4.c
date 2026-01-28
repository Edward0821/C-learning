#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
int main(void)
{
	int     year;
	double rate, capital, deposit;
	printf("Please enter year,capital:");
	scanf("%d,%lf", &year, &capital);
	switch (year)
	{
	case 1:	rate = 0.0225;	break;
	case 2:	rate = 0.0243;	break;
	case 3:	rate = 0.0270;	break;
	case 5:	rate = 0.0288;	break;
	case 8:	rate = 0.0300;	break;
	default:printf("Error rate!\n");
		exit(0);
	}
	deposit = capital * pow(1+rate, year);
	printf("rate = %f, deposit = %f\n", rate, deposit);
	return 0;
}
