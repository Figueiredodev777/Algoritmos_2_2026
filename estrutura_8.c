#include <stdio.h>
#include <string.h>

    struct cadastro{
        
        char nome[6][50];
        int dia[6];
        int mes[6];
        int ano[6];
    };

    int enconteOmaior(int ano[6], int tamanho){
    
    int maior = ano[0];
    for(int i = 0; i < tamanho; i++)
    {
        if(ano[i] < maior)
        {
            maior = ano[i];
        }
    }
    
    return maior;
}
    
    
    
int main(){
    
    struct cadastro pessoa;
    int maior;
    
    for(int j = 0; j < 6; j++){
        
        printf("Digite um nome: ");
        scanf("%49[^\n]", pessoa.nome[j]);
        getchar();
    }
    
    for(int i = 0; i < 6; i++){
        printf("  digite dia do aniversario de %s\n ", pessoa.nome[i]);
        scanf("%d", &pessoa.dia[i]);
        getchar();
        
        printf("Digite o mes do aniversario: \n");
        scanf("%d", &pessoa.mes[i]);
        getchar();
        
        printf("Digite o ano de nascimento: \n");
        scanf("%d", &pessoa.ano[i]);
        getchar();
    }
    
    maior = enconteOmaior(pessoa.ano, 6);
    printf("O mais Velho: %d\n", maior);
    
    
}
