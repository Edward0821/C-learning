#include  <stdlib.h>
#include  <stdio.h>
int main(void)
{
	int  magic;               /* 计算机"想"的数 */
	int  guess;               /* 用户猜的数 */
	magic = rand();          /* 调用随机函数"想"一个数magic */
	printf("Please guess a magic number:");
	scanf("%d", &guess);    /* 输入用户猜的数guess */
	if (guess > magic)   	  /*若guess>magic，则提示"Wrong!Too big"*/
		printf("Wrong! Too big!\n");
	else if (guess < magic)/*若guess<magic，则提示"Wrong!Too small"*/
		printf("Wrong! Too small!\n");
	else           	      /* 否则提示"Right!"并打印这个数 */
		printf("Right!\n");
    return 0;
}
