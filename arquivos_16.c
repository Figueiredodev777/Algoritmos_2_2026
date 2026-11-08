#include <stdio.h>

typedef struct {
    int codigo;
    char descricao[50];
    float preco;
} produto;

int existe(FILE *arq, int codigo) {
    produto p;
    rewind(arq);
    while (fscanf(arq, "%d %[^\n] %f", &p.codigo, p.descricao, &p.preco) != EOF) {
        if (p.codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *arquivo;
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
        
        if (existe(arquivo, p.codigo)) {
            printf("codigo ja existe\n");
            continue;
        }
        
        printf("descricao: ");
        scanf(" %[^\n]", p.descricao);
        printf("preco: ");
        scanf("%f", &p.preco);
        
        fprintf(arquivo, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
        fflush(arquivo);
        
        printf("adicionar outro produto? (s/n): ");
        scanf(" %c", &continuar);
        
    } while(continuar == 's' || continuar == 'S');
    
    fclose(arquivo);
    
    
    return 0;
}
