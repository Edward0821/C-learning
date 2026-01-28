//参考程序1
#include <stdio.h>
#include <math.h>
int GetBits(int n);
int CountBits(int n);
int main(void)
{
    int n, bits;
    printf("Input n:");
    scanf("%d", &n);
    bits = CountBits(n);
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
//函数功能：返回整数n的位数，并统计输出每一位数字出现的次数
int CountBits(int n)
{
    int digit, pos, i, j, k;
    int d0=0, d1=0, d2=0, d3=0, d4=0, d5=0, d6=0, d7=0, d8=0, d9=0;
    int bits;
    bits = GetBits(n);
    pos = bits;
    for (i=1; i<=bits; ++i)      //从最高位开始依次提取每位数字并计数
    {
        pos--;
        k = 1;
        for (j=1; j<=pos; ++j)
        {
            k = k * 10;
        }
        digit = fabs(n / k);         //提取每位数字
        switch (digit)                //对提取的位计数
        {
          case 0: d0++;    break;
          case 1: d1++;    break;
          case 2: d2++;    break;
          case 3: d3++;    break;
          case 4: d4++;    break;
          case 5: d5++;    break;
          case 6: d6++;    break;
          case 7: d7++;    break;
          case 8: d8++;    break;
          case 9: d9++;    break;
          default:printf("error\n");
        }
        n = fabs(n) - digit * k;    //去掉前一位数字，将后一位数字变成最高位
    }
    if (d0 != 0) printf("0: %d\n", d0);
    if (d1 != 0) printf("1: %d\n", d1);
    if (d2 != 0) printf("2: %d\n", d2);
    if (d3 != 0) printf("3: %d\n", d3);
    if (d4 != 0) printf("4: %d\n", d4);
    if (d5 != 0) printf("5: %d\n", d5);
    if (d6 != 0) printf("6: %d\n", d6);
    if (d7 != 0) printf("7: %d\n", d7);
    if (d8 != 0) printf("8: %d\n", d8);
    if (d9 != 0) printf("9: %d\n", d9);
    return bits;
}
//参考程序2
#include <stdio.h>
#include <math.h>
int GetBits(int n);
int CountBits(int n);
int main(void)
{
    int n, bits;
    printf("Input n:");
    scanf("%d", &n);
    bits = CountBits(n);
    printf("%d bits\n", bits);
    return 0;
}
int GetBits(int n)
{
    int  b;
    int  bits = 1;
    b = n / 10;
    while (b != 0)   //通过“不断缩小10倍直到为0为止”判断有几位数字
    {
        bits++;
        b = b / 10;
    }
    return bits;
}
int CountBits(int n)
{
    int  digit, bits, pos, i, j, k;
    int  count[10] = {0};
    bits = GetBits(n);
    pos = bits;
    for (i=1; i<=bits; ++i)      //从最高位开始依次提取每位数字并计数
    {
        pos--;
        k = 1;
        for (j=1; j<=pos; ++j)
        {
            k = k * 10;
        }
        digit = fabs(n / k);         //提取每位数字
        count[digit]++;              //对提取的位计数
        n = fabs(n) - digit * k;    //去掉前一位数字，将后一位数字变成最高位
    }
    for (j=0; j<10; ++j)
    {
        if (count[j] != 0) printf("%d: %d\n", j, count[j]);
    }
    return bits;
}
//参考程序3
#include <stdio.h>
#define  N  30
int GetBits(char num[]);
int CountBits(char num[]);
int main(void)
{
    int bits;
    char a[N];
    printf("Input n:");
    scanf("%s", a);
    bits = CountBits(a);
    printf("%d bits\n", bits);
    return 0;
}
//函数功能：返回num中数字字符的总数
int GetBits(char num[])
{
    int i, m = 0;
    for (i=0; num[i]!='\0'; ++i)
    {
        if (num[i] <= '9' && num[i] >= '0')
        {
            m++;
        }
    }
    return m;      //返回数字字符的个数
}
//函数功能：打印num中每个数字字符出现的次数,返回数字的位数
int CountBits(char num[])
{
    int i, bits;
    int  count[10] = {0};
    bits = GetBits(num);
    for (i=0; num[i]!='\0'; ++i)
    {
        switch(num[i])
        {
        case '0':
            count[0]++;
            break;
        case '1':
            count[1]++;
            break;
        case '2':
            count[2]++;
            break;
        case '3':
            count[3]++;
            break;
        case '4':
            count[4]++;
            break;
        case '5':
            count[5]++;
            break;
        case '6':
            count[6]++;
            break;
        case '7':
            count[7]++;
            break;
        case '8':
            count[8]++;
            break;
        case '9':
            count[9]++;
            break;
        }
    }
    for (i=0; i<10; ++i)
    {
        if (count[i] != 0)
            printf("%d: %d\n", i, count[i]);
    }
    return bits;
}

//参考程序4
#include <stdio.h>
#define  N  30
int GetBits(char num[]);
int CountBits(char num[]);
int main(void)
{
    int  bits;
    char a[N];
    printf("Input n:");
    scanf("%s", a);
    bits = CountBits(a);
    printf("%d bits\n", bits);
    return 0;
}
//函数功能：返回num中数字字符的总数
int GetBits(char num[])
{
    int i, m = 0;
    for (i=0; num[i]!='\0'; ++i)
    {
        if (num[i] <= '9' && num[i] >= '0')
        {
            m++;
        }
    }
    return m;      //返回数字字符的个数
}
//函数功能：打印num中每个数字字符出现的次数,返回数字的位数
int CountBits(char num[])
{
    int i, m, bits;
    int  count[10] = {0};
    bits = GetBits(num);
    for (i=0; num[i]!='\0'; ++i)
    {
        m = num[i] - '0';
        count[m]++;
    }
    for (i=0; i<10; ++i)
    {
        if (count[i] != 0)
            printf("%d: %d\n", i, count[i]);
    }
    return bits;
}
