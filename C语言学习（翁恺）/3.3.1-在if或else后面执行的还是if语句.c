#include <stdio.h>
int main()
{
int a,b,c,d;
scanf("%d %d %d",&a,&b,&c) ;
if(a>b)d=a;
else d=b;
if(d>c)printf("最大的数是%d",d);
else printf("最大的数是%d\n",c);
return 0;
}
