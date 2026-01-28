#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int number;
    int pi;
    int di;
} Virus;
int a(const void *a, const void *b) {
    Virus *va = (Virus *)a;
    Virus *vb = (Virus *)b;
    if (va->pi < vb->pi) return -1;
    else if (va->pi > vb->pi) return 1;
    else {
        if (va->di > vb->di) return -1;
        else if (va->di < vb->di) return 1;
        else return 0;
    }
}
int main() {
    int n,i;
    while (scanf("%d", &n)!= EOF) {
        Virus *f = (Virus *)malloc(n * sizeof(Virus));
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &f[i].number, &f[i].pi, &f[i].di);
        }

        qsort(f, n, sizeof(Virus), a);
        printf("result:\n");
        for (i = 0; i < n; i++) {
            printf("%d %d %d\n", f[i].number, f[i].pi, f[i].di);
        }
        free(f);
    }
    return 0;
}
