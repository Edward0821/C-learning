#include  <stdio.h>
#include  <string.h>
#define   WEEKDAYS  7             /*每星期天数*/
#define   MAX_STR_LEN  10         /*字符串最大长度*/
int main(void)
{
	int    i, pos;
	int    findFlag = 0;          /* 置找到标志为假 */
	char   x[MAX_STR_LEN];
	char   weekDay[][MAX_STR_LEN] = {"Sunday", "Monday", "Tuesday",
		"Wednesday", "Thursday", "Friday",								     "Saturday"};
	printf("Please enter a string:");
	scanf("%s", x);                /* 输入待查找的字符串 */
	for (i=0; i<WEEKDAYS && !findFlag; i++)
	{
		if (strcmp(x, weekDay[i]) == 0)
		{
			pos = i;          /*记录找到的位置*/
			findFlag = 1;    /*若找到，则置找到标志为真，退出循环*/
		}
	}
	if (findFlag)        /*找到标志为真，说明找到*/
	{
		printf("%s is %d\n", x, pos);
	}
	else                  /*找到标志为假，说明未找到*/
	{
		printf("Not found!\n");
	}
	return 0;
}
