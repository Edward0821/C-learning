#include <stdio.h>
int main()
{
int hour1,minute1;
int hour2,minute2;
printf("开始时间：");
scanf("%d %d",&hour1,&minute1);
printf("结束时间：");
scanf("%d %d",&hour2,&minute2);
int t1=hour1*60+minute1;//将小时分钟统一为分 
int t2=hour2*60+minute2;
int t=t2-t1;
printf("共耗时%d小时%d分",t/60,t%60);
}
	
	
	
