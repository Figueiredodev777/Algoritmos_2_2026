#include <stdio.h>
#include <stdlib.h>

int *somaColunas(int **A, int n) {
    int *B = (int *)malloc(n * sizeof(int));

    if (B == NULL) {
        return NULL;
    }

    for (int j = 0; j < n; j++) {
        B[j] = 0;
        for (int i = 0; i < n; i++) {
            B[j] += A[i][j];
        }
    }

    return B;
}

int main() {
    int n = 3;
    int **A = (int **)malloc(n * sizeof(int *));
    int *B;

    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }

    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
    A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

    B = somaColunas(A, n);

    for (int j = 0; j < n; j++) {
        printf("%d ", B[j]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(B);

    return 0;
}