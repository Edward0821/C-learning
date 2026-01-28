#include  <math.h>
#include <stdio.h>
int main(void)
{
	int n = 1, count =1;
	double e = 1.0, term = 1.0;
	while (fabs(term) >= 1e-5)
	{
		term = term / n;
		e = e + term;
		n++;
		count++;
	}
	printf("e = %f, count = %d\n", e, count);
	return 0;
}
