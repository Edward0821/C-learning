# include <stdio.h> 

int prime(int n)  /*判断n是否为一个素数，是则返回1，不是则返回0*/
{
    int i, flag;
    if (n<=1) 
        return 0;
    flag = 1;
    for (i=2;i<n; i++)
        if (n%i==0)
        {
            flag = 0;
            break;
        }
    return flag;        
}  

int main( )                              
{    
    int n;
    for (n=10; n<=20; n++)
        if ( prime(n)==1)    /*如果n是素数，则输出n*/
            printf("%5d", n);
    return 0;
}     
