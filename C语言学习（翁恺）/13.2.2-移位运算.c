#include <stdio.h>
int main()
{
int a=15;
printf("%d\n",a<<2);
//x<<=n等价于x*=2的n次方
 printf("%d\n",a>>2);
 /*x>>=n等价于x/=2的n次方 
 对于unsigned类型，左边填入0；
 否则左边填入原来的最高位（保持符号不变） 
 */
 int b=0x80000000;
 unsigned int b1=0x80000000;
 printf("%d\n",b);
   printf("%u\n",b1);
  printf("%d\n",b>>1);
   printf("%u",b1>>1);
return 0;
}
