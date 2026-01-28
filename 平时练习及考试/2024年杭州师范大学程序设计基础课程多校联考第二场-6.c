#include <stdio.h>
int main() 
{
int m,n,l,r,i,j;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
scanf("%d",&m);
scanf("%d%d",&l,&r);
for(i=0;i<m;i++){
int mid=(l+r)/2;
int h=1;
for(j=l-1;j<r;j++){
if(j<mid)
a[j]+=h++;
else if(j>mid){
a[j]+=--h;
}
else
a[j]+=h;
}
}
for(i=0;i<n;i++){
printf("%d ",a[i]);
}
return 0;
}
