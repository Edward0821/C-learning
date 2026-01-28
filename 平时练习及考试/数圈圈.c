# include<stdio.h>
int main(){
int x,shu,n,i,qq=0;
scanf("%d",&x);
scanf("%d",&shu);
for(i=0;i<x;i++){
	n=shu%10;
	shu/=10;
    if(n==0||n==6||n==9){
    qq++;
	    }
    if(n==8){
    qq+=2;
    }
    }
    printf("%d",qq);
    return 0;
} 

