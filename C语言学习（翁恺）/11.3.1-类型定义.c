#include<stdio.h>
typedef long int64;
typedef struct a{
int x;
int y;
}A;
typedef char* S[10];
int main(void){
A b={12,23};
int64 c=100000000;
S s={"hello","world","!"};
printf("%d %d\n",b.x ,b.y );
for(c=0;c<10;c++){
if(s[c]!=NULL)
printf("%s",s[c]);
}
return 0;
}

