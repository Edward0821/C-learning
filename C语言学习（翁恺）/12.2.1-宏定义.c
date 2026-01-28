#include<stdio.h>
#define PI 3.1415926
#define PI2 2*PI
#define PRT printf("%f\n",PI2);\
printf("%f\n",PI2*3.0)//在上一行末使用\表示下一行仍是这个宏 
#define FORMAT "%s,%s\n"
int main(){
printf("%s:%d\n",__FILE__,__LINE__);//输出该程序的储存地址和该代码在程序中的行数 
printf(FORMAT,__DATE__,__TIME__);//输出该程序最近一次的编译时间 
PRT;
return 0;
}
