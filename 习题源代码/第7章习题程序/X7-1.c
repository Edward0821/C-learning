#include <stdio.h>
int hour, minute, second;          /* 定义全局变量 */
void update(void)
{
	second++;
	if (second == 60)
	{
		second = 0;
		minute++;
	}
	if (minute == 60)
	{
		minute = 0;
		hour++;
	}
	if (hour == 24)
		hour = 0;
}
void display(void)
{
	printf("%2d:%2d:%2d\r", hour, minute, second);
}
void delay(void)
{
	int t;
	for (t=0; t<100000000; t++);/* 用循环体为空语句的循环实现延时 */
}
int main(void)
{
	int i;
	hour = minute = second = 0;
	for(i=0; i<1000000; i++)    /* 利用循环结构，控制时钟运行的时间 */
	{
		update();                 /* 更新时、分、秒显示值 */
		display();                /* 显示时分秒 */
		delay();                  /* 模拟延迟时间为1秒 */
	}
	return 0;
}
