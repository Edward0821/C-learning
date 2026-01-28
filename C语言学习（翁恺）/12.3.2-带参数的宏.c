#include<stdio.h>
#define cube(x) ((x)*(x)*(x))
#define RADTODEG(x) ((x)*50) 
int main(){
	int x;
scanf("%d",&x);
printf("%d\n",cube(x));
printf("%d\n",1000/RADTODEG(x));
return 0;
}
