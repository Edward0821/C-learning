 #include<stdio.h>
  int gAll=10;
  //全局变量不初始化默认为0 
 int f(void){
printf("in %s gAll=%d\n",__func__,gAll);
gAll+=2;
printf("agn in %s gAll=%d\n",__func__,gAll );
 } 
int main(){
printf("in %s gAll=%d\n",__func__,gAll);
f();
gAll+=2;
printf("agn in %s gAll=%d\n",__func__,gAll );
return 0;
}
 
