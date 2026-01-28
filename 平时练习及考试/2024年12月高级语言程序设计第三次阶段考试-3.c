#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    char m[9];
    float t;
    int k;
    int c=0;
    for(i=0;i<n;i++){
        scanf("%s %f %d",m,&t,&k);
        if(t>=37.5&&k==1){
            c++;
            printf("%s\n",m);
        }
    }
    printf("%d",c);
}
