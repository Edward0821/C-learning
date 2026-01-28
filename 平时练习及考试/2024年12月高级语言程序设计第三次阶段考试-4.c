#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    gets(s);
    int a[100];
    int len=strlen(s);
    int c=0,n=0,i;
    for(i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            n=n*10+(s[i]-'0');
        if(i==len-1||s[i+1]<'0'||s[i+1]>'9'){
                a[c++]=n;
                n=0;
            }
        }
    }
    printf("%d\n",c);
    for(i=0;i<c;i++){
        printf("%d",a[i]);
        if(i<c-1){
            printf(" ");
        }
    }
}
