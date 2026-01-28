#include <stdio.h>
#include <math.h>
void sum(int *d,int a[],int z){
int i,c;
for(i=0;i<z;i++){
for(c=2;c<sqrt(a[i]);c++){
if(a[i]%c==0)
break;
*d+=a[i]*a[i];
}
if(a[i]==2)
*d+=8;
if(a[i]%2==0&&a[i]!=2)
*d+=a[i]*2;
if(a[i]%3==0)
*d+=a[i]*3;
}
}
int main(){
int n,m,i,sumn=0,sumy=0;
int count=0;
scanf("%d %d",&n,&m);
int a[n],b[m];
char h,j;
for(i=0;i<n;i++){
scanf("%d",&a[i]);
count++;
}
scanf("%c",&h);
if(h=='Y')
sum(&sumy,a,count);
else if(h=='N')
sum(&sumn,a,count);
for(i=0;i<n;i++){
count=0;
scanf("%d",&b[i]);
count++;
}
scanf("%c",&j);
if(j=='Y')
sum(&sumy,b,count);
else if(j=='N')
sum(&sumn,b,count);
if(sumn<sumy)
printf("heiheihei!");
else if(sumn>=sumy)
printf("yingyingying!");
return 0;
}
