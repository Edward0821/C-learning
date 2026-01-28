#include <stdio.h>
int main()
{
int price=0;
int bill=0;
printf("请输入商品金额(元)：");
scanf("%d",&price);
printf("请输入支付金额(元)：");
scanf("%d",&bill) ;
if(bill>=price){
printf("应该找您：%d（元）",bill-price) ;
}
else{
printf("您的钱不够，您仍需要支付：%d（元）",price-bill) ;
}
}
