#include <stdio.h>
int main() 
{
int n,i,p,min;
scanf("%d",&n);
scanf("%d",&p);
min=p;
for(i=1;i<n;i++){
scanf("%d",&p);
if(p<min)
min=p;
}
printf("%d",min);
return 0;
}
