#include <stdio.h>
#include <string.h>
int i ;
int a(int n) {
    char str[100];
    sprintf(str, "%d", n);
    int len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int x, y, count = 0;
    scanf("%d %d", &x, &y);
    int num;
    for ( num= x; num <= y; num++) {
        if (a(num)) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}

