#include  <time.h>
#include  <stdlib.h>
#include  <stdio.h>
int main(void)
{
	int  magic, guess, counter = 0;
	int ret;                                 /* 保存函数scanf()的返回值 */
	srand(time(NULL));
	magic = rand() % 100 + 1;
	do{
		printf("Please guess a magic number:");
		ret = scanf("%d", &guess);
		while (ret != 1) /* 若存在输入错误，则重新输入 */
		{
			while (getchar() != '\n');  /* 清除输入缓冲区中的非法字符 */
			printf("Please guess a magic number:");
			ret = scanf("%d", &guess);
		}
		counter++;
		if (guess > magic)
			printf("Wrong!Too big!\n");
		else if (guess < magic)
			printf("Wrong!Too small!\n");
		else
			printf("Right!\n");
	} while (guess!=magic && counter<10); /*猜不对且未超过10次时继续猜*/
	printf("counter = %d\n", counter);
	return 0;
}
