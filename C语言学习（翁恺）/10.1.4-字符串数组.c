/*#include<stdio.h>
int main(int argc,char const *argv[]){
int i;
for(i=0;i<argc;i++){
printf("%d:%s\n",i,argv[i]);
}
	return 0;
}
这是本节程序参数的例子 
*/
#include<stdio.h>
int main(){
char *a[]={"January","February","March","April","May","June",
"July","August","September","October","November","December"};
int yf;
scanf("%d",&yf);
printf("%s",a[yf-1]); 
	return 0;
}
