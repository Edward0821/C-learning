#include<stdio.h>
#include<string.h>

int main(){
int n;
scanf("%d",&n);
getchar();
char a[101],b[101];
fgets(a,sizeof(a),stdin);
if(a[strlen(a)-1]=='\n'){
a[strlen(a)-1]=='\0';
}
fgets(b,sizeof(b),stdin);
if(b[strlen(b)-1]=='\n'){
b[strlen(b)-1]=='\0';
}
int p=strcmp(a,b);
if(p<0)
printf("%s",a);
else if(p==0)
printf("NO");
else if(p>0)
printf("%s",b);
	return 0;
}

