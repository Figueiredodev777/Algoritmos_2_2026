#include <stdio.h>
#include <stdlib.h>

    int** alocarMatriz(int linhas, int colunas) {
    int **matriz = (int**)malloc(linhas * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("erro na alocação de memória!\n");
            exit(1);
        }
    }
    
    return matriz;
    
    }

    int buscarValor(int **matriz, int linhas, int colunas, int valor) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (matriz[i][j] == valor) {
                    return 1; 
                }
            }
        }
    return 0;
    }
    
    void preencherMatriz(int **matriz, int linhas, int colunas) {
    printf("preencha a matriz %dx%d:\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
    

int main(){
    
    int linhas, colunas, valor;
    int **matriz;
    
    printf("digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("digite o número de colunas: ");
    scanf("%d", &colunas);
    
    if (linhas <= 0 || colunas <= 0) {
        printf("dimensoes invalidas\n");
        return 1;
    }
    
    matriz = alocarMatriz(linhas, colunas);
    preencherMatriz(matriz, linhas, colunas);
    
    
    printf("digite o valor a ser buscado: \n");
    scanf("%d", &valor);
    
    int resultado = buscarValor(matriz, linhas, colunas, valor);
    
    if (resultado == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    
    free(matriz);
    
    
    
    return 0;
}
