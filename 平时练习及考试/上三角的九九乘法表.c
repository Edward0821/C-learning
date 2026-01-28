#include <stdio.h>
int main()
{
int a,b,c;
scanf("%d",&a);
printf("1  2  3  4  5  6  7  8  9  \n");
for(b=1;b<a;b++)
{
for(c=1;c<=b;c++){
if(c<b)
printf("   ");
else
printf("%3d",b*c);
}
}
return 0;
}
