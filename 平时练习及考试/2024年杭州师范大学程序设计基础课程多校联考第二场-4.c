#include <stdio.h>
int main() 
{
int a,b,c,n=0;
scanf("%d%d%d",&a,&b,&c);
while(a<=c&&b<=c){
	if(a<b)
	a=a+b;
	else
	b=a+b;
	n++;
}
printf("%d",n);
return 0;
}
