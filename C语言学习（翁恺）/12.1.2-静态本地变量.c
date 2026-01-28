#include<stdio.h>
int gAll;
  //全局变量不初始化默认为0 
int f(void){
int k=0;
static int all=1;
printf("   k=%p\n",&k);
 printf(" all=%p\n",&all);
 printf("gAll=%p\n",&gAll);
printf("in %s all=%d\n",__func__,all);
all+=2;
printf("agn in %s all=%d\n",__func__,all );
 } 
int main(){
f();
f();
return 0;
}
 
