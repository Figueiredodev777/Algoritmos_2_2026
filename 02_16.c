#include <stdio.h>
#include <stddef.h>

int* busca_subvetor(int *vetor, int tam_v, int *sub, int tam_s) {
    
    if (vetor == NULL || sub == NULL || tam_s <= 0 || tam_v < tam_s) 
    {
        return NULL;
    }

    
    for (int i = 0; i <= tam_v - tam_s; i++) 
    {
        int j;
        
        
        for (j = 0; j < tam_s; j++) 
        {
            if (vetor[i + j] != sub[j]) {
                break; 
            }
        }
        
        if (j == tam_s) {
            return &vetor[i]; 
        }
    }

    return NULL; 
}


int main() {
    int vetor_principal[] = {1, 5, 8, 9, 2, 4, 7};
    int subvetor[] = {9, 2, 4};
    
    int tam_v = sizeof(vetor_principal) / sizeof(vetor_principal[0]);
    int tam_s = sizeof(subvetor) / sizeof(subvetor[0]);

    int *resultado = busca_subvetor(vetor_principal, tam_v, subvetor, tam_s);

    if (resultado != NULL) {
        printf("sub vetor encontrado: %ld\n", resultado - vetor_principal);
    } else {
        printf("sub vetor nao nulo.\n");
    }

    return 0;
}
