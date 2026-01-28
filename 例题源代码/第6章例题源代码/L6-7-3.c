#include  <stdlib.h>
#include  <stdio.h>
int main(void)
{
	int  magic, guess, counter = 0;
	unsigned int seed;           		/* 定义一个无符号型整型变量 */
	printf("Please enter seed:"); 	/* 提示输入随机数种子 */
	scanf("%u", &seed);				/* 输入函数srand()所需要的参数 */
	srand(seed);       	/* 为函数rand()设置随机数种子 */
	magic = rand() % 100 + 1;
	do{
		printf("Please guess a magic number:");
		scanf("%d", &guess);
		counter++;
		if (guess > magic)
			printf("Wrong! Too big!\n");
		else if (guess < magic)
			printf("Wrong! Too small!\n");
		else
			printf("Right!\n");
	}while (guess != magic);
	printf("counter = %d\n", counter);
	return 0;
}
