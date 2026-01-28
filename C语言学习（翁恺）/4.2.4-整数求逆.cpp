#include<stdio.h>
int main()
{
int x;
scanf("%d",&x);
int a;
int b=0;
while (x>0){
a=x%10;
//printf("%d",a);
b=b*10+a;
//printf("x=%d,a=%d,b=%d\n",x,a,b);
x/=10;
}
printf("%d",b);
return 0;
}
