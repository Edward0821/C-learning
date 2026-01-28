#include <stdio.h>
int main()
{
int a=123;
printf("%+09d\n",a);
double b=123.0;
printf("%9.2f\n",b);
printf("%*d\n",6,a);

printf("%hhd",(char)12345);
int num;
int i1=scanf("%*d%d",&num);
int i2=printf("%d\n",num);
printf("%d:%d\n",i1,i2);
int num1;
scanf("%i\n",&num1);
printf("%d",num1);
return 0;
}
