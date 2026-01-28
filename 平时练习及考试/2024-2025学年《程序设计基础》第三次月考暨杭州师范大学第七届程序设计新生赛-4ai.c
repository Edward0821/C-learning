#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    int b = -1, e = -1,i;
    for (i = 0; i < n; i++) {
        if (s[i] == '(') {
            b = i;
        } else if (s[i] == ')') {
            e = i;
            break;
        }
    }

    if (b!= -1 && e!= -1) {
        char be[e - b];
        int k = 0,i;
        for (i = b + 1; i < e; i++) {
            be[k++] = s[i];
        }
        be[k] = '\0';

        char result[1000];
        k = 0;
        for (i = 0; i < b; i++) {
            result[k++] = s[i];
        }
        for (i = 0; i < strlen(be); i++) {
            if (be[i] == 'A') {
                result[k++] = 'A';
                result[k++] = 'A';
            } else if (be[i] == 'B') {
                result[k++] = 'B';
                result[k++] = 'B';
            }
        }
        for (i = e + 1; i < n; i++) {
            result[k++] = s[i];
        }
        result[k] = '\0';
        strcpy(s, result);
    }

    int total_value = 0;
    for (i = 0; i < strlen(s); i++) {
        int value = 0;
        if (s[i] == 'A') {
            value = 2;
        } else if (s[i] == 'B') {
            value = 1;
        }
        if (i > 0) {
            if (s[i - 1] == s[i]) {
                if (s[i] == 'A') {
                    value += 2;
                } else if (s[i] == 'B') {
                    value += 2;
                }
            } else if ((s[i - 1] == 'A' && s[i] == 'B') || (s[i - 1] == 'B' && s[i] == 'A')) {
                value += 1;
            }
        }
        if (i < strlen(s) - 1) {
            if (s[i + 1] == s[i]) {
                if (s[i] == 'A') {
                    value += 2;
                } else if (s[i] == 'B') {
                    value += 2;
                }
            } else if ((s[i + 1] == 'A' && s[i] == 'B') || (s[i + 1] == 'B' && s[i] == 'A')) {
                value += 1;
            }
        }
        total_value += value;
    }
    printf("%d\n", total_value);
    return 0;
}
