#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
char a[]="Hello World!";
char *p=strchr(a,'l');
p=strchr(p+1,'l');
//1.重复查找字符方法 
printf("%s\n",p);

char *t=(char*)malloc(strlen(p)+1);
strcpy(t,p);
printf("%s\n",t);
free(t);
//复制查找到的字符后面剩余字符串的方法 

char c=*p;
*p='\0';
char *t1=(char*)malloc(strlen(a)+1);
strcpy(t1,a);
printf("%s\n",t1);
free(t1);
*p=c;
//复制查找到的字符前面剩余字符串的方法

char b[]="World";
char *d= strstr(a,b);
printf("%s",d);
//在字符串a中寻找字符串b

/*char e[]="world";
char *g= strcasestr(a,e);
printf("%s",g);
 
strcasestr函数可以不分大小写的查找，但在Windows系统中不支持该函数 
*/
return 0;
}
