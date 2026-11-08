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
    
    arquivo = fopen("PRODUTOS.txt", "a+");
    
    if (arquivo == NULL) {
        printf("erro ao criar arquivo\n");
        return 1;
    }
    
    do {
        printf("codigo: ");
        scanf("%d", &p.codigo);
        getchsr();
        printf("descricao: ");
        scanf(" %49[^\n]", p.descricao);
        getchsr();
        printf("preco: ");
        scanf("%f", &p.preco);
        getchsr();
        fprintf(arquivo, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
        
        printf("adicionar outro produto? (s/n): ");
        scanf(" %c", &continuar);
        
    } while(continuar == 's' || continuar == 'S');
    
    fclose(arquivo);
    
    arquivo = fopen("PRODUTOS.txt", "r");
    temp = fopen("TEMP.txt", "w");
    
    int excluidos = 0;
    
    while (fscanf(arquivo, "%d %[^\n] %f", &p.codigo, p.descricao, &p.preco) != EOF) {
        if (p.preco > 200.00) {
            printf("excluindo: %s - R$ %.2f\n", p.descricao, p.preco);
            excluidos++;
        } else {
            fprintf(temp, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
        }
    }
    
    fclose(arquivo);
    fclose(temp);
    
    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");
    
    
    
    return 0;
}
