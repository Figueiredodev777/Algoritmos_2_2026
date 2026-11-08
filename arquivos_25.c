#include <stdio.h>

typedef struct {
    int codigo;
    char descricao[50];
    float preco;
} produto;

int main() {
    FILE *arquivo;
    FILE *temp;
    produto p;
    char continuar;
    float preco_min, preco_max, desconto;
    
    arquivo = fopen("PRODUTOS.txt", "a+");
    
    if (arquivo == NULL) {
        printf("erro ao criar arquivo\n");
        return 1;
    }
    
    do {
        printf("digite o codigo do produto: ");
        scanf("%d", &p.codigo);
        getchar();
        printf("digite a descricao do produto: ");
        scanf(" %49[^\n]", p.descricao);
        getchar();
        printf("digite o preco do produto: ");
        scanf("%f", &p.preco);
        getchar();
      
        fprintf(arquivo, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
        
        printf("digite  1 para adicionar outro produto: ");
        scanf(" %c", &continuar);
        
    } while(continuar == 1);
    
    fclose(arquivo);
    
    printf("digite o preco minimo: ");
    scanf("%f", &preco_min);
    getchar();
    printf("digite o preco maximo: ");
    scanf("%f", &preco_max);
    getchar();
    printf("digite o percentual de desconto: ");
    scanf("%f", &desconto);
    getchar();
  
    arquivo = fopen("PRODUTOS.txt", "r");
    temp = fopen("TEMP.txt", "w");
    
    int alterados = 0;
    
    while (fscanf(arquivo, "%d %[^\n] %f", &p.codigo, p.descricao, &p.preco) != EOF) {
        if (p.preco >= preco_min && p.preco <= preco_max) {
            float novo_preco = p.preco * (1 - desconto/100);
            printf("aplicando desconto: %s - de R$ %.2f para R$ %.2f\n", p.descricao, p.preco, novo_preco);
            p.preco = novo_preco;
            alterados++;
        }
        fprintf(temp, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
    }
    
    fclose(arquivo);
    fclose(temp);
    
    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");
    
    
    
    return 0;
}
