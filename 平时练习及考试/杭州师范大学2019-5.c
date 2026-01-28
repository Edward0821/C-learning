#include <stdio.h>
int main()
{
	double a,b,c,d,e=0,f,g; 
	scanf("%lf",&a);
	for(b=1;b<=a;b++)
	{
	scanf("%lf",&c);
    for(d=1;d<=c;d++)
    {
    scanf("%lf",&e);
    f+=e;
	}
	g=f/d;
	if(g>0.75)
	printf("WWtql!\n");
	else
	printf("WWtcl!\n");
	}
	
 } 
