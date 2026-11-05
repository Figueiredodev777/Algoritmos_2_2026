#include <stdio.h>
#include <stdlib.h>

int *funcao(int n){
    
    

    int *vetor = (int *) calloc(n, sizeof(int));
    
     if (vetor == NULL) {
        printf("falha na alocaco de memória.\n");
         
    }
    
    for(int i = 0; i < n; i++){
        
        vetor[i] = i;  
        
    }    
    
    
    return vetor;
}

int main()
{
    int n, tamanho;
    printf("digite o valor para N\n");
    scanf("%d", &n);
    getchar();
    
    tamanho = n;
    
    
    int *vetor = funcao(n);
    
    for(int i = 0; i < tamanho; i++)
    {
        
        printf("%d ", vetor[i]);
        
    }
    
    
    

    return 0;
}
