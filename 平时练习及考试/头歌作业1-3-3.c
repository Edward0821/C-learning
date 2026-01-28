#include <stdio.h>

int main() {
    int n,i,j,k;
    printf("请输入一个正整数 n：");
    scanf("%d", &n);

    // 输出上半部分菱形
    for (i = 1; i <= n; i++) {
        // 输出空格
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // 输出星号
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // 输出下半部分菱形
    for (i = n - 1; i >= 1; i--) {
        // 输出空格
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // 输出星号
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
