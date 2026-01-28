#include    <stdio.h>
#include    <stdlib.h>
int  DayofYear(int year, int month, int day);
void  MonthDay(int year, int yearDay, int *pMonth, int *pDay);
void  Menu(void);
int dayTab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},						    {0,31,29,31,30,31,30,31,31,30,31,30,31}};
int main(void)
{
	int    year, month, day, yearDay;
	char   c;
	Menu();          	/* 调用Menu函数显示一个固定式菜单 */
	c = getchar();    	/* 输入选择 */
	switch (c)        	/* 判断选择的是何种操作 */
	{
	case '1':
		printf("Please enter year, month, day:");
		scanf("%d,%d,%d", &year, &month, &day);
		yearDay = DayofYear(year, month, day);
		printf("yearDay = %d\n", yearDay);
		break;
	case '2':
		printf("Please enter year, yearDay:");
		scanf("%d,%d", &year, &yearDay);
		MonthDay(year, yearDay, &month, &day);
		printf("month = %d, day = %d\n", month, day);
		break;
	case '3':
		exit(0);   /* 退出程序的运行 */
	default:
		printf("Input error!");
	}
	return 0;
}
/* 函数功能：对给定的某年某月某日，计算并返回它是这一年的第几天 */
int  DayofYear(int year, int month, int day)
{
	int  i, leap;
	/* 若year为闰年，即leap值为1，则用第1行元素dayTab[1][i]计算；
	否则leap值为0，用第0行dayTab[0][i]计算 */
	leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	for (i=1; i<month; i++)
	{
		day = day + dayTab[leap][i];
	}
	return day;         /* 返回计算出的day的值 */
}
/* 函数功能：对给定的某一年的第几天，计算它是这一年的第几月第几日 */
void  MonthDay(int year, int yearDay, int *pMonth, int *pDay)
{
	int  i, leap;
	leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	for (i=1; yearDay>dayTab[leap][i]; i++)
	{
		yearDay = yearDay - dayTab[leap][i];
	}
	*pMonth = i;        /* 将计算出的月份值赋值给pMonth所指向的变量 */
	*pDay = yearDay;   /* 将计算出的日号赋值给pDay所指向的变量 */
}
/* 函数功能：显示菜单 */
void  Menu(void)
{
	printf("1. year/month/day -> yearDay\n");
	printf("2. yearDay -> year/month/day\n");
	printf("3. Exit\n");
	printf("Please enter your choice:");
}
