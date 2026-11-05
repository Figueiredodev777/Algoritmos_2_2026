#include <stdio.h>
#include <stdlib.h>

int *produtoMatrizVetor(int **A, int *B, int n) {
    int *C = (int *)malloc(n * sizeof(int));

    if (C == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        C[i] = 0;
        for (int j = 0; j < n; j++) {
            C[i] += A[i][j] * B[j];
        }
    }

    return C;
}

int main() {
    int n = 3;
    int **A = (int **)malloc(n * sizeof(int *));
    int B[3] = {1, 2, 3};
    int *C;

    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }

    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
    A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

    C = produtoMatrizVetor(A, B, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", C[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(C);

    return 0;
}