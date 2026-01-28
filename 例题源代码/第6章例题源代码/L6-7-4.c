#include  <time.h>        /* 将函数time()所需要的头文件time.h包含到程序中 */
#include  <stdlib.h>
#include  <stdio.h>
int main(void)
{
	int  magic, guess, counter = 0;
	srand(time(NULL));                  /* 为函数rand()设置随机数种子 */
	magic = rand() % 100 + 1;
	do{
		printf("Please guess a magic number:");
		scanf("%d", &guess);
		counter ++;
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
