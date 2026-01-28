#include<stdio.h>
#include<math.h>
int main(){
double i,n,a,b,j=0;
scanf("%lf",&n);
b=n;
for(i=1;;i++){
b-=pow(2,i-1);
j++;
if(b<=0)
break;
}
for(i=0;i<j;i++){
n-=pow(2,i);
}
printf("%.0lf\n",n);
for(i=0;i<j;i++){
printf("%.0lf ",pow(2,i));
}
return 0;
}
