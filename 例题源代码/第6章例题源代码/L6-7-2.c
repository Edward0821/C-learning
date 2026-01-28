#include  <stdlib.h>
#include  <stdio.h>
int main(void)
{
	int  magic, i;
	srand(1);                    /* 设置随机数种子为1 */
	for (i=0; i<10; i++)
	{
	     magic = rand() % 100 + 1;
         printf("%d ", magic);
	}
	printf("\n");
	return 0;
}
