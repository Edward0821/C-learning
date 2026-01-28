#include<stdio.h>
int swap(int*m,int*n);
int main(){
int a,b;
scanf("%d%d",&a,&b);
printf("%p %p\n",a,b);
printf("%p %p\n",&a,&b);
swap(&a,&b);
printf("%d %d\n",a,b);
printf("%p %p\n",a,b);
printf("%p %p\n",&a,&b);
return 0;
}
int swap(int*m,int*n){
int t;
t=*m;
*m=*n;
*n=t;
}
