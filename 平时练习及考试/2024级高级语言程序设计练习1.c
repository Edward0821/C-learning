#include <stdio.h>
int main()
{
int a,b;
for(a=1;a<=5;a++)
{
for(b=5;b>=a;b--){
printf("* ");
}
printf("\n");
}
return 0; 
}
