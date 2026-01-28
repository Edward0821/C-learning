#include<stdio.h>
int jc(long long int n){
long long int j;
int x=1;
for(x=1;x<=20;x++){
j*=x;
if(j==n){
break;
}
}
return x;
}
int main(){
long long int a;
scanf("%lld",&a);
int y=jc(a);
printf("%d\n",y);
return 0;
}

