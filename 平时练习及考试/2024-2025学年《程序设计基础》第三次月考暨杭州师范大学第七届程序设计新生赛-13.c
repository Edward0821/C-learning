#include<stdio.h>
int main()
{long long int x=1000000000000000000;
int j=1,n;
long long int hw[x];
 hw[1]=0;
	int a,b,i;
	for(b=0;b<x;b++){
     a=0;
     i=b;
     while(i!=0){
     a=a*10+i%10;
    i/=10;
      }
      if(b==a){
       j++;
      	hw[j]=a;
	  }
     }
     scanf("%d",&n);
printf("%lld",hw[n]);
   return 0;
}
