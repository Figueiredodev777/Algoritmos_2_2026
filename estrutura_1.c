#include <stdio.h>
#include <string.h>


    struct Dados {
        
        char nome[100];
        int idade;
        char endereco[100];
        
        
    };
    
    
int main(){

  int a, mult;
  printf("Digite um numero inteiro");
  scanf("%d", &a)
if(a % 2 == 0){

    mult = a * a;
  
}

  printf("O quadrado do numero e:%d", mult);
  
  return 0;
}
        
        struct Dados pessoa1;
        
        
        strcpy(pessoa1.nome, "Rogerio");
        pessoa1.idade = 0;
        pessoa1.endereco;
        
        printf("Digite sua idade\n");
        scanf("%d", &pessoa1.idade);
        getchar();
        printf("Digite seu endereco\n");
        scanf("%99[^\n]", pessoa1.endereco);
        getchar();
        
        
        printf("Nome: %s\n", pessoa1.nome);
        printf("idade:  %d\n", pessoa1.idade);
        printf("Endereco: %s", pessoa1.endereco);
        
        return 0;
    }
