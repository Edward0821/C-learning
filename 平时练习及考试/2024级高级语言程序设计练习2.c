#include <stdio.h>
int main()
{
int a;
int b;
int sum=0;
scanf("%d",&a);
for(b=2;b<=a;b=b+2)
{
sum+=b;
}
printf("sum = %d\n",sum);
return 0; 
}
