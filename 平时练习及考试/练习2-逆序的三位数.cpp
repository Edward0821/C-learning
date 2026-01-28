#include <stdio.h>
int main()
{
int a;
printf("输入一个三位数：");
scanf ("%d",&a);
int b=a/100;
int c=a%10;
int d=a%100/10;
int e=c*100+d*10+b;
printf("%d",e);
}
