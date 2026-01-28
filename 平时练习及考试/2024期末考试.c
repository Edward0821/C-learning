#include <stdio.h>
#include <math.h>
// 计算能组成沙漏的最大行数
int calculateRows(int n) {
    int i;
    for (i = 1; ; i++) {
        if (2 * i * i - 1 > n) {
            return i - 1;
        }
    }
}
// 打印沙漏
void printHourglass(int rows, char symbol) {
    int i, j, k;
    for (i = rows; i >= 1; i--) {
        for (j = 0; j < rows - i; j++) {
            printf(" ");
        }
        for (k = 0; k < 2 * i - 1; k++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
    for (i = 2; i <= rows; i++) {
        for (j = 0; j < rows - i; j++) {
            printf(" ");
        }
        for (k = 0; k < 2 * i - 1; k++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}
int main() {
    int n;
    char symbol;
    scanf("%d %c", &n, &symbol);
    int rows = calculateRows(n);
    printHourglass(rows, symbol);
    int usedSymbols = 2 * rows * rows - 1;
    int remainingSymbols = n - usedSymbols;
    printf("%d\n", remainingSymbols);
    return 0;
}
