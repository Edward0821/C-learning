//自动计数的枚举 
#include<stdio.h>
enum color{red,yellow,blue,numcolors};
int main(){
int color=-1;
char *colornames[numcolors]={"red","yellow","blue"};
char *colorname=NULL;
printf("输入你喜欢的颜色代码：");
scanf("%d",&color);
if(color>=0&&color<numcolors){
	colorname=colornames[color];
}else{
	colorname="unknown";
}
printf("你喜欢的颜色是：%s\n",colorname);
return 0;
}
