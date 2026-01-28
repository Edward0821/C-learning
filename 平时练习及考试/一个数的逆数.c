#include<stdio.h>
void solve(int n){
    printf("%d", n%10);
    /*********Begin*********/
    n=n/10;
    /*********End**********/
    if(n>0) solve(n);
}
int main(void)
{
    int n;
    scanf("%d",&n);
    solve(n);
    return 0;
}

