#include <stdio.h>
#include <stdlib.h>

/*Escreva uma função que receba um vetor de inteiros, seu tamanho e um número X
(informado pelo usuário). A função deve buscar X no vetor e retornar um ponteiro para
a primeira posição de memória onde X foi encontrado.
-Se X não estiver no vetor, a função deve retornar NULL.
-Apresente o resultado na main.*/


int* buscar_elemento(int *vetor, int tamanho, int x) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == x) {
            return &vetor[i]; 
        }
    }
    return NULL; 
}

int main() {
    int n, x, *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    

    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Posição [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor X que deseja buscar: ");
    scanf("%d", &x);

    
    int *resultado = buscar_elemento(vetor, n, x);

    if (resultado != NULL) {
        printf("O valor %d foi encontrado\n", *resultado);
        printf("Endereço de memoria: %p\n", (void*)resultado);
        printf("indice no vetor: %ld\n", resultado - vetor); 
    } else {
        printf("NULL.\n", x);
    }


    return 0;
}


