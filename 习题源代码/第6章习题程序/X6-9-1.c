#include  <math.h>
#include <stdio.h>
int main(void)
{
	int	n = 1, count =1;
	double	e = 1.0, term = 1.0;
	long	fac = 1;
	for (n=1; fabs(term) >= 1e-5; n++)
	{
		fac = fac * n;
		term = 1.0 / fac;
		e = e + term;
		count++;
	}
	printf("e = %f, count = %d\n", e, count);
	return 0;
}
