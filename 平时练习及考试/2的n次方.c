#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    long long result = 1LL << n;
    printf("%lld", result);
    return 0;
}
