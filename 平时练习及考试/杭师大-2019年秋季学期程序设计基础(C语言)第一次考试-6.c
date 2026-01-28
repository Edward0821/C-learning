#include<stdio.h>
int main(){
int  a,b,n,c,k,d,e;
char sf;
scanf("%d",&a);
for(b=0;b<a;b++){
scanf("%d%d%d",&n,&c,&k);
for(e=1;e<n;e++){
scanf("%d%c",&d,&sf);
if(sf=='Y')
c=c-2;
else if(d<k)
c--;
}
if(c<=0)
printf("awsl");
else 
printf("heihei");
}
	return 0;
}
