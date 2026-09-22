#include <stdio.h>
#include <string.h>


struct Atleta {
    char nome[50];
    char esporte[30];
    int idade;
    float altura;
};

int main() {
    
    struct Atleta atletas[5];
  
    
   
    for(int i = 0; i < 5; i++) {
        printf("Atleta %d:\n", i + 1);
        
        printf("Nome: ");
        fgets(atletas[i].nome, 50, stdin);
       
        atletas[i].nome[strcspn(atletas[i].nome, "\n")] = '\0';
        
        printf("Esporte: ");
        fgets(atletas[i].esporte, 30, stdin);
        atletas[i].esporte[strcspn(atletas[i].esporte, "\n")] = '\0';
        
        printf("Idade: ");
        scanf("%d", &atletas[i].idade);
        getchar();
      
        printf("Altura (em metros): ");
        scanf("%f", &atletas[i].altura);
        getchar();
       
        
    }
    
    
    int indice_mais_alto = 0;
    int indice_mais_velho = 0;
    
    for(int i = 1; i < 5; i++) {
       
        if(atletas[i].altura > atletas[indice_mais_alto].altura) {
            indice_mais_alto = i;
        }
        
        
        if(atletas[i].idade > atletas[indice_mais_velho].idade) {
            indice_mais_velho = i;
        }
    }
    
    
    printf("Atleta mais alto: %s (%.2f metros)\n", 
           atletas[indice_mais_alto].nome, 
           atletas[indice_mais_alto].altura);
    
    printf("Atleta mais velho: %s (%d anos)\n", 
           atletas[indice_mais_velho].nome, 
           atletas[indice_mais_velho].idade);
    
    return 0;
}
