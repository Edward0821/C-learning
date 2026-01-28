#include<stdio.h>
void solve(int n){ 
    int temp=n%10;
    /*********Begin*********/

    /*********End**********/
    if(n/10!=0)
    solve(n/10);
      printf("%d ", temp);
}
int main(void)
{
    int n;
    scanf("%d",&n);
    solve(n);
    return 0;
}

