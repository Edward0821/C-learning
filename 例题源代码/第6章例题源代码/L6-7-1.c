#include  <stdlib.h>
#include  <stdio.h>
int main(void)
{
	int  magic;                       /* 计算机"想"的数 */
	int  guess;              	         /* 用户猜的数 */
	int  counter = 0;                /* 计数器，记录用户猜的次数，初始化为0 */
	magic = rand() % 100 + 1;      /* 生成一个1到100之间的随机数 */
	do{
		printf("Please guess a magic number:");
		scanf("%d", &guess);      	/* 输入用户猜的数guess */
		counter++;                 	/* 计数器变量count加1 */
		if (guess > magic)
			printf("Wrong! Too high!\n");
		else if (guess < magic)
			printf("Wrong! Too small!\n");
		else
			printf("Right!\n");
	}while (guess != magic);              /* 执行循环直到猜对为止 */
	printf("counter = %d\n", counter);  /* 打印用户猜数的次数count */
	return 0;
}
