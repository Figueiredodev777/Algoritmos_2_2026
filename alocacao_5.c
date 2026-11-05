#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int *V;
    do{
        
        printf("digite um numero inteiro positivo: \n");
        scanf("%d", &a);
    
   } while (a < 0);
   
    V = (int*)malloc(a * sizeof(int));
    
    if (V == NULL) {
        printf("erro na alocacao de memoria!\n");
        return 1;
    }
    
     for (int i = 0; i < a; i++) 
     {
      
        do {
            printf("V[%d] = ", i);
            scanf("%d", &V[i]);
            
            if (V[i] < 2) {
                printf(" um valor maior ou igual a 2.\n");
            }
        } while (V[i] < 2);
    }
   
   printf("Vetor V lido:\n");
    for (int i = 0; i < a; i++) {
        printf("V[%d] = %d\n", i, V[i]);
        
    }
   
   free(V);
}