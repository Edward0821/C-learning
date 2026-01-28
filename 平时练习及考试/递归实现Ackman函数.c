#include<stdio.h>
int Acm(int m,int n){
    if(m==0&&n>0)
        /*********Begin*********/
     return n+1;
        /*********End**********/
    else if(n==0&&m>0)
        /*********Begin*********/
     {
     	m=m-1;
      Acm(m,1);
	 }
        /*********End**********/
    else
        /*********Begin*********/
     {n=Acm(m,n-1);
	 m=m-1;
     Acm(m,n);
	 }
	 /*********End**********/
}
int main(void)
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d", Acm(m,n));
    return 0;
}

