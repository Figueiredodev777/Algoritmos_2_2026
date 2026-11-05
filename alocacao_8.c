#include <stdio.h>
#include <stdlib.h>

int* funcao(int N)
{
    if (N <= 0)
    {
        return NULL;
    }

    int *vetor = (int*)malloc(N * sizeof(int));
    return vetor;
}


int main()
{
    int N;
    printf("digite o tamanho do vetor: ");
    scanf("%d", &N);
    
    int *vetor = funcao(N);
    
    if(vetor == NULL)
    {
        printf("Tamanho invalido.\n");
    }
    else
    {
        printf("vetor alocado.\n");
        
        
        free(vetor);
    }
    
    return 0;
}
