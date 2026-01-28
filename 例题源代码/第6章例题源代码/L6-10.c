#include  <time.h>
#include  <stdlib.h>
#include  <stdio.h>
int main(void)
{
	int  magic, guess, counter = 0, ret;
	char reply;				                   /* 保存用户输入的回答 */
	srand(time(NULL));
	do{
		magic = rand() % 100 + 1;
		do{
			printf("Please guess a magic number:");
			ret = scanf("%d", &guess);
			while (ret != 1)                 /* 若存在输入错误，则重新输入 */
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
		} while (guess!=magic && counter<10); /*猜不对且未超10次继续猜*/
		printf("counter = %d\n", counter);
		printf("Do you want to continue(Y/N or y/n)?"); /*提示是否继续*/
		scanf(" %c", &reply);                  /* %c前有一个空格 */
	}while (reply=='Y' || reply=='y');       /* 输入Y或y则程序继续 */
	return 0;
}
