#include <stdio.h>

int main() {
    int m, n, temp, r;
 
    scanf("%d%d", &m, &n);

    // 确保 m 不小于 n，若 m 小于 n，则交换 m 和 n 的值
    if (m < n) {
        temp = m;
        m = n;
        n = temp;
    }

    // 求最大公约数
    while (n!= 0) {
        r = m % n;
        m = n;
        n = r;
    }
    int greatestCommonDivisor = m;

    // 求最小公倍数，根据最小公倍数 = 两数之积 / 最大公约数
    int leastCommonMultiple = m * n / greatestCommonDivisor;

    printf("最大公约数为：%d\n", greatestCommonDivisor);
    printf("最小公倍数为：%d\n", leastCommonMultiple);

    return 0;
}
