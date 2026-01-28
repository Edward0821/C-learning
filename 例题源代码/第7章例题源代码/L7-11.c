#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_NUMBER 100
#define MIN_NUMBER 1
#define MAX_TIMES  10
int MakeNumber(void);
void GuessNumber(const int number);
int IsValidNum(const int number);
int IsRight(const int number, const int guess);

int main(void)
{
       int number;                    /* 计算机生成的随机数 */
	   char reply;                    /* 用户对于是否继续猜数的回答 */
	   srand(time(NULL));            /* 初始化随机种子 */
	   do{
		   number = MakeNumber();    /* 计算机生成一个随机数 */
		   GuessNumber(number);      /* 用户猜数字 */
		   printf("Do you want to continue(Y/N or y/n)?");  /*提示是否继续*/
		   scanf(" %c", &reply);               /* %c前有一个空格 */
	   }while (reply=='Y' || reply=='y');   /* 输入Y或y则程序继续 */
	   return 0;
}
/* 	函数功能：  	用户猜数字
  	函数参数：  	number是计算机生成的数
   	函数返回值：	无
 */
void GuessNumber(const int number)
{
	   int guess;			/* 用户猜的数*/
       int count = 0;		/* 用户猜的次数 */
	   int right = 0;	     /* 猜的结果对错与否 */
	   int ret;                /* 记录scanf()的返回值，即读入的数据项数 */
	   do{
		   printf("Try %d:", count+1);
		   ret = scanf("%d", &guess);      /* 读入用户猜的数 */
		   /* 处理用户输入，判断是否有输入错误，是否在合法的数值范围内 */
		   while (ret != 1 || !IsValidNum(guess))
		   {
			   printf("Input error!\n");
			   while (getchar() != '\n'); /* 清除输入缓冲区中的错误数据 */
			   printf("Try %d:", count+1);
		       ret = scanf("%d", &guess); /* 读入用户猜的数 */
		   }
		   count++;		                      /* 记录用户猜的次数 */
		   right = IsRight(number, guess); /* 判断用户猜的数是大还是小 */
	   }while (!right && count < MAX_TIMES);
	   if (right)        /* 若用户猜对了，则输出相应的提示信息 */
         printf("Congratulations! You try %d times. You're so cool!\n", count);
    else                /* 若超过MAX_TIMES次仍未猜对，输出相应的提示信息 */
         printf("Mission failed after %d attempts.\n", MAX_TIMES);
}

/*	函数功能：  	计算机生成一个随机数
 	函数参数：  	无
   	函数返回值：	返回计算机生成的随机数
 */
int MakeNumber(void)
{
    int number;
    number = (rand() % (MAX_NUMBER - MIN_NUMBER + 1) ) + MIN_NUMBER;
	assert(number >= MIN_NUMBER && number <= MAX_NUMBER);
    return number;
}
/* 	函数功能：  	判断用户的输入是否在合法的数值范围（1-100）之内
    函数参数：  	number是用户输入的数
    函数返回值：	若合法，则返回非0值；否则，返回0
*/
int IsValidNum(const int number)
{
    if (number >= MIN_NUMBER && number <= MAX_NUMBER)
		return 1;
	   else
		   return 0;
}
/* 	函数功能： 	判断guess和number谁大谁小
                猜大了，提示"Wrong! Too high."，猜小了，提示"Wrong! Too low."
    函数参数： 	number是被猜的数，guess是猜的数息
    函数返回值：如果猜对，则返回1；否则，返回0
*/
int IsRight(const int number, const int guess)
{
	if (guess < number)      /* 若猜小了，输出相应的提示信息 */
	{
		printf("Wrong! Too small!\n");
		return 0;
	}
	else if (guess > number) /* 若猜大了，输出相应的提示信息 */
	{
		printf("Wrong! Too big!\n");
		return 0;
	}
	else return 1;
}
