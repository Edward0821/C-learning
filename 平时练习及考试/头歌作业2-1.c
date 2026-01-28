#include <stdio.h>
//定义main函数
int main()
{
    //定义三个数
  double a,b,c,d;
    //请在此添加‘输入三个数，按由大到小顺序输出这三个数’的代码
    /*****************Begin******************/
    scanf("%lf %lf %lf",&a,&b,&c);
	if(a>b){
    d=a;
    a=b;
    b=d;
	} 
	if(b>c){
	d=b;
	b=c;
	c=d;
	}
	if(a>b){
	d=a;
	a=b;
	b=d;
	}
    printf("%g %g %g",c,b,a) ; 
    /***************** End ******************/
    return 0;
}
