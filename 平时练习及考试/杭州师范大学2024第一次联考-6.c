#include <stdio.h>
int main() 
{
int a,b,c;
scanf("%d",&a);
for(b=0;b<a;b++){
for(c=0;c<3;c++){
if(c==0){
printf("*   *\n");
}else if(c==1){
printf(" * * \n");
}else{
printf("  *  \n");
}
}
}
return 0;
}
