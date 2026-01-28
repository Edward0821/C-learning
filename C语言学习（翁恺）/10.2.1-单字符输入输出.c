#include<stdio.h>
int main(){
int a;
while((a=getchar())!=EOF){
	putchar(a);
}
printf("EOF"); 
	return 0;
}
/*运行时CTRL+C可强制停止程序运行     CTRL+Z代表输入了“EOF ”*/
