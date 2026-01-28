# include <stdio.h> 
int main(){
struct student{
char ID[5];
char xm[10];
int s[3];
}STUDENT;
int n,i,j;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%s %s",&ID,&xm);
for(j=0;j<3;j++){
scanf("%d",&s[j]);
}
}
return 0;
} 

