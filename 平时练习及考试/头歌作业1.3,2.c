//包含标准输入输出函数
#include <stdio.h>
//定义main函数
int main()
{
    //请在此添加‘求水仙花数’的代码
    /*****************Begin******************/
    int n=100,i,j,k; 
	do{
	
	
i =n/100;
j =n/10-i*10;
k =n%10;
if(n==i*i*i+j*j*j+k*k*k&&n!=0)
printf("%d ",n);
n++;
	 }
	 while(n<1000);
    /***************** End ******************/
    return 0;
}
