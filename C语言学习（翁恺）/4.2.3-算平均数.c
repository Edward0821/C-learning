#include<stdio.h>
int main()
{
int a;
int b=0;
int c=0;
printf("每输入一个整数按一次回车键，输入-1来结束输入计算平均数") ; 
scanf("%d",&a);
while(a!=-1){
b+=a;
c++;
scanf("%d",&a);
}
printf("%f\n",1.0*b/c);
return 0;
 } 
 
