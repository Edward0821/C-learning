#include<stdio.h>
int main(){
int x,a=2;
scanf("%d",&x);
if(x<0)
a=0;
if(x==0)
a=1;
switch(a){
case 0:
	printf("-1");
	break;
	case 1:
	printf("0");
	break;
	default:
	printf("%d",2*x);
	break;
}
return 0;
}
