#include<stdio.h>
int main()
{
int a;
int n=0;
printf("输入一个正整数：");
scanf("%d",&a);
a/=10;
n++;
while(a>0){
n++;
a/=10;
}
printf("这是一个%d位数",n);
}
