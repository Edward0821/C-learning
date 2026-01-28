#include <stdio.h>
int main() 
{
int a,n,c;
scanf("%d",&a);
for(n=1;;n++){
c+=(n+1)*(n+2)/2;
if(c>=a){
printf("%d",n);
break;
}
else
continue;
}
return 0;
}
