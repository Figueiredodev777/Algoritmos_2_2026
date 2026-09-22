#include <stdio.h>


void imprimirVetor(int *vetor, int tamanho) {
    int *ptr = vetor;  
    int *fim = vetor + tamanho; 
    
    printf("Vetor: [");
    
    
    while (ptr < fim) {
        printf("%d", *ptr);  
        
        ptr++;
        if (ptr < fim) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int vetor[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    imprimirVetor(vetor, tamanho);
    
    return 0;
}
