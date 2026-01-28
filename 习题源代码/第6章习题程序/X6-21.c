#include <stdio.h>
int main(void)
{
	int  n = 0, t;
	for (t=0; t<=20*7; t++)
	{
		if (t%5 == 0 && t <= 20*5)
		{
			n++;
			continue;
		}
		if (t%6 == 0 && t <= 20*6)
		{
			n++;
			continue;
		}
		if (t%7 == 0)
		{
			n++;
		}
	}
	printf("n = %d\n", n);
	return 0;
}
