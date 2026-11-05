#include <stdio.h>
#include <stdlib.h>

int** matrizidentidade(int n) {
    int** matriz = (int**)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
        
        for (int j = 0; j < n; j++) {
            
            if (i == j) {
                matriz[i][j] = 0;
            } else if (i < j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = -1;
            }
            
        }
    }
    
    return matriz;
}

void libera_matriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int n;
   
    printf("digite um valor pra n: ");
    scanf("%d",  &n);
    getchar();
   
    int** mat = matrizidentidade(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    
    libera_matriz(mat, n);
    return 0;
}
