#include <stdio.h>
int main()
{
int a=0;
printf("输入开始时间：");
scanf("%d",&a);
int hour1=a/100;
int minute1=a%100;
int t1=hour1*60+minute1;
int t2;
printf("输入经过时间（分）："); 
scanf("%d",&t2);
int t=t1+t2;
int hour2=t/60;
int minute2=t%60;
printf("结束时间为：  %d:%d",hour2,minute2);
return 0;
}
