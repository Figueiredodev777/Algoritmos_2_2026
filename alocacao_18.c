#include <stdio.h>
#include <stdlib.h>

int **multiplicaMatrizes(int **A, int **B, int linhasA, int colunasA, int linhasB, int colunasB) {
    if (colunasA != linhasB) {
        return NULL;
    }

    int **C = (int **)malloc(linhasA * sizeof(int *));
    if (C == NULL) {
        return NULL;
    }

    for (int i = 0; i < linhasA; i++) {
        C[i] = (int *)malloc(colunasB * sizeof(int));
        if (C[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(C[k]);
            }
            free(C);
            return NULL;
        }
    }

    for (int i = 0; i < linhasA; i++)
     {
        for (int j = 0; j < colunasB; j++) 
        {
            C[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {
    int linhasA = 2, colunasA = 3;
    int linhasB = 3, colunasB = 2;

    int **A = (int **)malloc(linhasA * sizeof(int *));
    for (int i = 0; i < linhasA; i++) {
        A[i] = (int *)malloc(colunasA * sizeof(int));
    }

    int **B = (int **)malloc(linhasB * sizeof(int *));
    for (int i = 0; i < linhasB; i++) {
        B[i] = (int *)malloc(colunasB * sizeof(int));
    }

    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;

    int **C = multiplicaMatrizes(A, B, linhasA, colunasA, linhasB, colunasB);

    if (C != NULL) {
        for (int i = 0; i < linhasA; i++) {
            for (int j = 0; j < colunasB; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Erro na multiplicacao de matrizes.\n");
    }

    for (int i = 0; i < linhasA; i++) {
        free(A[i]);
    }
    free(A);

    for (int i = 0; i < linhasB; i++) {
        free(B[i]);
    }
    free(B);

    if (C != NULL) {
        for (int i = 0; i < linhasA; i++) {
            free(C[i]);
        }
        free(C);
    }

    return 0;
}