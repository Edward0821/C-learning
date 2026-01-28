#include <stdio.h>

int CS(int num) {
    int count = 0,i;
    for (i = 1; i <= num/2; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    int b = 0;
    int a = 0;
    int num;
    for (num = r; num >= l; num--) {
        int c = CS(num);
        if (c >=b) {
           b = c;
            a = num;
        }
    }
    printf("%d %d\n", a,b);
    return 0;
}
