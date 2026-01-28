#include <stdio.h>
int main(void)
{
    int days;
    printf("Input days:");
    scanf("%d", &days);
    int x = 1;
    while (days > 1)
    {
        x = (x + 1) * 2;
        days--;
    }
    printf("x=%d\n", x);
    return 0;
}
