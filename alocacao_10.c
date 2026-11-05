#include <stdio.h>
#include <stdlib.h>

int* c_vetor(int N, int valor) {
    if (N <= 0) return NULL;
    
    int* vetor = (int*)malloc(N * sizeof(int));
    
    for (int i = 0; i < N; i++) {
        vetor[i] = valor;
    }
    
    return vetor;
}

int main() {
    int tamanho, valor;
    
    printf("Tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    printf("Valor para preencher: ");
    scanf("%d", &valor);
    
    int* vetor = c_vetor(tamanho, valor);
    
    if (vetor == NULL) {
        printf("tamanho invalido!\n");
    } else {
        printf("vetor: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", vetor[i]);
        }
        
        free(vetor);
    }
    
    return 0;
}
