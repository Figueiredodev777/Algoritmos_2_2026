#include <stdio.h>
#include <stdlib.h>

int *somaVetores(int A[], int B[], int n) {
    int *C = (int *)malloc(n * sizeof(int));

    if (C == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        C[i] = A[i] + B[i];
    }

    return C;
}

int main() {
    int n;
    int *A, *B, *C;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    A = (int *)malloc(n * sizeof(int));
    B = (int *)malloc(n * sizeof(int));

    if (A == NULL || B == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(A);
        free(B);
        return 1;
    }

    printf("Digite os elementos do vetor A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Digite os elementos do vetor B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    C = somaVetores(A, B, n);
    if (C == NULL) {
        printf("Erro ao alocar memoria para C.\n");
        free(A);
        free(B);
        return 1;
    }

    printf("Vetor C:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    free(A);
    free(B);
    free(C);
    return 0;
}


