#include <stdio.h>
#include <stdlib.h>


int main()
{
    
    int *p_vetor;
    int vetor;
    
    printf("Digite o tamanho do vetor para ser lido: \n");
    scanf("%d", &vetor);
    
    
    if(vetor <= 0){

        
        printf("Valor invalido\n");
        
    }
    
    p_vetor = (int*)malloc(vetor * sizeof(int));
    
    for(int i = 0; i < vetor; i++)
    {
        printf("espaco %d\n", i + 1);
        scanf("%d", &p_vetor[i]);
    }
    
     printf("Vetor digitado: ");
   
     for (int i = 0; i < vetor; i++) 
    {
        printf("%d", p_vetor[i]);
        if (i < vetor - 1) 
        {
            printf(", ");
        }
    }
    
    free(p_vetor);

    return 0;
}
