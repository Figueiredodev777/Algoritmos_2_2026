#include <stdio.h>

int main()
{
    float valor[10];
    float *p_valor;
    p_valor = &valor[0];
    
    for(int i = 0; i < 10; i++){
        
        scanf("%f", &valor[i]);
        
    }
    
    for(int i = 0; i < 10; i++){
        
        
        printf("Endereço do elemento %d: %p\n", i+1, p_valor);
        p_valor++;
        
    }
    
}
