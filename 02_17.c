#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *vetor, int tamanho) {
    if (tamanho <= 1) return;

    int *fim = vetor + tamanho - 1;
    int *ptr;
    int trocou;

    while (fim > vetor) 
    {
        trocou = 0;
        
        for (ptr = vetor; ptr < fim; ptr++) 
        {
            if (*ptr > *(ptr + 1)) 
            {
                swap(ptr, ptr + 1); 
                trocou = 1;
            }
        }
        
        if (!trocou) 
        {
            break; 
        }
        
        fim--;
    }
}

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    for (int i = 0; i < tamanho; i++) 
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    bubble_sort(vetor, tamanho);

    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++) 
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
