#include <stdio.h>

void preencher_vetor(int *vetor, int valor, int tamanho) {
    int *fim = vetor + tamanho;
    
    while (vetor < fim) {
        *vetor++ = valor;
    }
}


int main() {
    int vetor[5];
    
    preencher_vetor(vetor, 7, 5);
    
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    
    
    return 0;
}
