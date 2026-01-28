#include <stdio.h>
int main()
{
int a=0b10000100;
int b=0b01001100;
int c=a&b;
printf("%d\n",c);
int c1=a|b;
printf("%d\n",c1);
int c2=~a;
printf("%d\n",c2);
int c3=-a;
printf("%d\n",c3);
int c4=a^b;
printf("%d\n",c4);
return 0;
}
