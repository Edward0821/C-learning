#include <stdio.h>
int main() 
{
double a,b,c;
scanf("%lf%lf",&a,&b);
c=b/a;
if(c>0&&c<=0.1){
printf("Au");
}
else if(c>0.1&&c<=0.3){
	printf("Ag");
}
else if(c>0.3&&c<=0.6){
	printf("Cu");
}
else printf("Sign Up");
return 0;
}
