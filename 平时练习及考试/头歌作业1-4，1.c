#include <stdio.h>

int main() {
    int n,i,j,k;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        int sum = 0;
        int factors[100];
        int factorCount = 0;
        for (j = 1; j < i; j++) {
            if (i % j == 0) {
                factors[factorCount++] = j;
                sum += j;
            }
        }
        if (sum == i) {
            printf("%d=", i);
            for (k = 0; k < factorCount - 1; k++) {
                printf("%d+", factors[k]);
            }
            printf("%d\n", factors[factorCount - 1]);
        }
    }
    return 0;
}
