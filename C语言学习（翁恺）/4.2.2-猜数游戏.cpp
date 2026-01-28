#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main()
{
srand(time(0));
int number=rand()%1000+1;
int count=0;
int a=0;
printf("我已经想好了一个1-1000之间的整数,"); 
do{
printf("请你猜猜我想的整数：");
scanf("%d",&a);
count++;
if(a>number){
printf("你猜的数大了，再猜猜吧。"); 
} 
else if(a<number){
printf("你猜的数小了，再猜猜吧。"); 
}
}
while(a!=number);
printf("太棒了！你只用了%d次就猜到了我想的数。\n",count);
}
