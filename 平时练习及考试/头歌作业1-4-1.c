#include <stdio.h>
#define M 1000
int main()
{
    int i, j, k, sum, num, s = 0, a[M], h;
    scanf("%d", &k);
    for (i = 2; i < k; i++)
    {
        sum = 1;
        s = 0;
        for (j = 1; j <= 0.5 * i; j++)
        {
            if (0 == i % j && j!= 1)
            {
                sum += j;
                a[s] = j;
                s++;
            }
            if (sum == i)
            {
                printf("%d=1", i);
                for (h = 0; h < s; h++)
                {
                    printf("+%d", a[h]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
