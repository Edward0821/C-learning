#include <stdio.h>
int main()
{int amount=100;
int price =0;
printf("请输入商品金额（元）：");
 scanf("%d",&price); 
 printf("请输入支付金额（元）："); 
 scanf("%d",&amount);
 int change=amount-price;
 printf("找你%d元。"); 
}
