#include<stdio.h>
int main(){
int n,a,b,c,d,e=0,f=0;
scanf("%d",&n);
for(a=0;a<n;a++){
	b=0;
	scanf("%d",&b);
	d=b;
	for(c=0;d>0;d/=10){
	if(d%10==4){
	c=1;
	break;
	}
}
if(c==0){
e+=b;
f++;
}
}
printf("%d\n%d",e,f); 
	return 0;
}
