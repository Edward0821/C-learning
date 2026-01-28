#include<stdio.h>
long long int fx(int x){
long long int w;
w=x*x-x+5;
return w;
}
long long int gx(int x){
long long int z;
z=2*x*x+x-3;
return z;
}
int main(){
int x;
long long int f,s,y;
scanf("%d",&x);
y=fx(gx(fx(x)-x))+gx(x);
printf("%d",y);
return 0;
}
