#include<stdio.h>
//编写最大公约数GCD函数
/*********Begin*********/
int GCD(long long int a,long long int b){
	long long int gcd,i;
	for(i=a;i>=1;i--){
		if(a%i==0&&b%i==0)
		{
			gcd=i;
			return gcd;
		}
		             }
	}
/*********End**********/ 

//编写最小公倍数LCM函数
/*********Begin*********/
long long int LCM(long long int a,long long int b,long long int c){
	long long int lcm;
	lcm=a*b/c;
	return lcm;
}
/*********End**********/ 
int main(void)
{  
    /*********Begin*********/
long long int a,b,maxg,miny;
scanf("%lld%lld",&a,&b);
if(a<=0||b<=0){
	printf("Input Error");
	return 0;
}
maxg=GCD(a,b);
miny=LCM(a,b,maxg);
printf("%lld %lld",maxg,miny);
    /*********End**********/ 
    return 0;
}

