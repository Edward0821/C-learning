#include <stdio.h>
#include <math.h>
int main(){
const double pi=3.14159;
double n,i,a,b,c,s=0,p=0;
scanf("%lf",&n);
for(i=0;i<n;i++){
scanf("%lf%lf%lf",&a,&b,&c);
if(a+b>c&&a+c>b&&b+c>a){
p=(a+b+c)/2;
s=(4*pi*p*(p-a)*(p-b)*(p-c))/pow(a+b+c,2);
printf("%.2f\n",s);
}
else
printf("Oh my god!!\n");
}
return 0;
}
