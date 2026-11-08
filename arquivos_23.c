#include <stdio.h>

typedef struct {
    int codigo;
    char descricao[50];
    float preco;
} produto;

int main() {
    FILE *arquivo;
    produto p;
    char letra;
    float preco_min, preco_max;
    char continuar;
    
    arquivo = fopen("PRODUTOS.txt", "a+");
    
    if (arquivo == NULL) {
        printf("erro ao criar arquivo\n");
        return 1;
    }
    
    do {
        printf("codigo: ");
        scanf("%d", &p.codigo);
        printf("descricao: ");
        scanf(" %[^\n]", p.descricao);
        printf("preco: ");
        scanf("%f", &p.preco);
        
        fprintf(arquivo, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
        
        printf("adicionar outro produto? (s/n): ");
        scanf(" %c", &continuar);
        
    } while(continuar == 's' || continuar == 'S');
    
    fclose(arquivo);
    
    arquivo = fopen("PRODUTOS.txt", "r");
    
    printf("digite a letra inicial: ");
    scanf(" %c", &letra);
    
    printf("digite o preco minimo: ");
    scanf("%f", &preco_min);
    
    printf("digite o preco maximo: ");
    scanf("%f", &preco_max);
    
    printf("produtos que comecam com '%c' e preco entre %.2f e %.2f:\n", letra, preco_min, preco_max);
    
    int encontrou = 0;
    
    while (fscanf(arquivo, "%d %[^\n] %f", &p.codigo, p.descricao, &p.preco) != EOF) {
        if ((p.descricao[0] == letra || p.descricao[0] == letra - 32 || p.descricao[0] == letra + 32) && p.preco >= preco_min && p.preco <= preco_max) {
            printf("codigo: %d, descricao: %s, preco: %.2f\n", p.codigo, p.descricao, p.preco);
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("nenhum produto encontrado\n");
    }
    
    fclose(arquivo);
    
    return 0;
}
