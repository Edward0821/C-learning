#include<stdio.h>
#include<string.h>
int main(){
char a[]="hello world!";
printf("%lu\n",strlen(a));
/*strlen函数计算字符串长度
 自编strlen函数mylen：
 int mylen(const char*s){
 int cnt=0;
 while(s[cnt]!='\0'){
 cnt++;
 }
 return cnt;
 } 
 */
 char b[]="ni hao!";
 printf("%d\n",strcmp(a,b));
 /*strcmp函数比较两个字符串大小：1.相等返回0；2.前大于后返回1；3.后大于前返回-1；
 自编strcmp函数mycmp:输出两个字符串相差的ASCII码值 
 int mycmp(const char*s1,const char *s2){
  /*1.int idx=0;
  while(){
  	if(s1[idx]!=s2[idx]){
  		break;
	  }
	  else if(s1[idx]=='\0'){
	  	break;
	  }
	  idx++;
  }*/
  /*2.while(s1[idx]==s2[idx]&&s1[idx]!='\0'){
  idx++
  }//
  return s1[idx]-s2[idx];
 }
 */
 /*3.
 whlie(*s1==*s2&&*s1!='\0'){
 s1++;
 s2++;
 }
 return *s1-*s2;
 */
	return 0;
}

