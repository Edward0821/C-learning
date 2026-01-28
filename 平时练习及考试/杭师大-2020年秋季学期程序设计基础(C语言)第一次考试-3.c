#include<stdio.h>
#include<math.h> 
int main(){
	int n,i,pt=0,gt=0,gd=0,ms=0,m;
int a[n],b[n];
scanf("%d",&n);
for(i=0;i<n;i++){
	scanf("%d",&a[i]);
} 
for(i=0;i<n;i++){
	scanf("%d",&b[i]);
} 
for(i=0;i<n;i++){
m=fabs(a[i]-b[i]);
if(m>=0&&m<=10)
pt++;
else if(m>10&&m<=20)
gt++;
else if(m>20&&m<=30)
gd++;
else if(m>30)
ms++;
} 
printf("%d\n%d\n%d\n%d\n",pt,gt,gd,ms);

return 0;
}
