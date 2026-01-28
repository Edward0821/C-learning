#include <stdio.h>
#include <string.h>
#define N 80
void Inverse(char str[]);
int main(void)
{
    char a[N];
    printf("Input a string:");
    gets(a);
    Inverse(a);
    printf("Inversed results:");
    puts(a);
    return 0;
}
void Inverse(char str[])
{
    int   len, i;
    char  temp;
    len = strlen(str);
    for (i=0; i<len/2; i++)
    {
		temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}
