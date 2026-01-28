#include <stdio.h>
void a(int (*arr)[5], int rows, int *max, int *row, int *col);

int main(){
	int i,j;
    int scores[3][5];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    int m, r, c;
    a(scores, 3, &m, &r, &c);
    printf("最高分是:%d\n", m);
    printf("行数是:%d\n", r);
    printf("列数是:%d\n", c);
    return 0;
    }
    void a(int (*arr)[5], int rows, int *max, int *row, int *col) {
    *max = arr[0][0];
    *row = 0;
    *col = 0;
    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 5; j++) {
            if (arr[i][j] > *max) {
                *max = arr[i][j];
                *row = i ;
                *col = j ;
            }
        }
    }
}
