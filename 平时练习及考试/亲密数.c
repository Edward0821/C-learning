#include<stdio.h>
#include<math.h> 
int main(void){
    /*********Begin*********/
int a,b,n,i,j;
for(a=1;a<3001;a++){
for(i=1,b=0;i<a;i++){
if(a%i==0){
b+=i;
}
for(j=1,n=0;j<b;j++){
if(b%j==0){
n+=j;
}
}
}
if(n==a&&a<b){
printf("(%d,%d)",a,b);
}
}
    /*********End**********/
    return 0;
}
