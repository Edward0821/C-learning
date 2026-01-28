#include <stdio.h>
int main()
{
const double RATE=15;
const int STANDARD=40;
double pay=0.0;
int hours;

printf("输入您本周工作的时间：");
scanf("%d",&hours);
printf("\n");
if(hours>STANDARD)
pay=STANDARD*RATE+(hours-STANDARD)*(RATE*1.5);
else
pay=hours*RATE;
printf("应付工资：%f\n",pay);

}
