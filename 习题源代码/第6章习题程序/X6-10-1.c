#include <stdio.h>
int main(void)
{
	int  i, j, k, n;
	for (n=100; n<1000; n++)
	{
		i = n / 100;			     /*分离出百位*/
		j = (n - i * 100) / 10;	/*分离出十位*/
		k = n % 10;				     /*分离出个位*/
		if (n == i*i*i + j*j*j + k*k*k)
		{
			printf("%6d", n);	     /*输出结果*/
		}
	}
	printf("\n");
	return 0;
}
