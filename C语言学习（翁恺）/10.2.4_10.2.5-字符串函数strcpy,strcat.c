#include<stdio.h>
#include<string.h>
int main(){
char a[]="abc";
char b[]="defg";
printf("%s   %s\n",strcpy( a, b),a);
//将前面的字符串替换成后面的字符串
printf("%s\n",strncpy( a, b,3));
char c[]="hello ";
char d[]="world!";
 printf("%s  %s\n",strcat(c,d),c);
 //将后面的字符串复制到前面字符串的末尾 
  printf("%s",strncat(c,d,5));
return 0;
}
