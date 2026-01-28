#include <stdio.h>
int main()
{
int a,b,c=1;
scanf("%d",&a);
for(b=2;b<a;b++){
if(a%b==0){
	c=0;
	break; 
}
}
if(c==0){
printf("%d不是素数",a); 
}else{printf("%d是素数",a); 
}}
