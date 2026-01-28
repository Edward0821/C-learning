#include<stdio.h>
long long solve(long long n){
    /*********Begin*********/
long long int i,j=1;
for(i=1;i<=n;i++){
j*=i;
}
return j;
    /*********End**********/
}
int main(void)
{
    long long n,i; 
    scanf("%lld",&n);
    long long ans=0;
    for(i=1;i<=n;i++)
        ans+=solve(i);
    printf("%lld", ans);
    return 0;
}

