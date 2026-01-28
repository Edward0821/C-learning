#include <stdio.h>
int GetBits(int n);
int main(void)
{
     int n, bits;
     printf("Input n:");
     scanf("%d", &n);
     bits = GetBits(n);
	printf("%d bits\n", bits);
     return 0;
}
//函数功能：返回整数n的位数
int GetBits(int n)
{
    int bits = 1;
    int b;
    b = n / 10;
    while (b != 0) //通过“不断缩小10倍直到为0为止”判断有几位数字
    {
        bits++;
        b = b / 10;
    }
    return bits;
}
