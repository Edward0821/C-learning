# include <stdio.h> 
#define N 80
int main(){
int i,j,t=0;
char a;
scanf("%c",&a);
getchar();
char b[N];
gets(b);
//printf("%s",b); 
for(i=0;b[i]!='\0';i++){
if(b[i]==a){
t=i+1;
}
}
if(t>0)
printf("index=%d",t);
else
printf("Not Found");
return 0;
} 

