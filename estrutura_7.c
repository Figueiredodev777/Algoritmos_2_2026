#include <stdio.h>
#include <string.h>

int enconteOmaior(int hora[5], int tamanho){
    
    int maior = hora[0];
    for(int i = 0; i < tamanho; i++)
    {
        if(hora[i] > maior)
        {
            maior = hora[i];
        }
    }
    
    return maior;
}

struct Horarios
{
   int hora[5];
   int minutos[5];
   int segundos[5];
};

int main()
{
    struct Horarios tempo[5];
    int maior;
   
   
    
        for(int i = 0; i < 5; i++)
        {
            printf("Digite a hora:");
            scanf("%d", &tempo->hora[i]);
            
            printf("Digite os minutos:");
            scanf("%d", &tempo->minutos[i]);
            
            printf("Digite os segundos:");
            scanf("%d", &tempo->segundos[i]);
        
        }
    
     maior = enconteOmaior(tempo->hora, 5);
    printf("A maior hora é: %d\n", maior);
    
    return 0;
    
}
    
    
