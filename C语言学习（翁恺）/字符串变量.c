#include<stdio.h>
int main(){
	char s[]="hello world!";
	char *s1="hello world!";
	s[11]='.';
	printf("%p\n",s);
	printf("%p\n",s1);
	printf("%s\n",s);
	printf("%s",s1);
	return 0;
}
