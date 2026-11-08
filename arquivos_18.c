#include <stdio.h>

typedef struct {
    int codigo;
    char descricao[50];
    float preco;
} produto;

int codigo_existe(FILE *arq, int codigo) {
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
    FILE *temp;
    produto p;
    int continuar;
    
    arquivo = fopen("PRODUTOS.txt", "a+");
    temp = fopen("TEMP.txt", "w");
    
    if (arquivo == NULL) {
        printf("erro ao criar arquivo\n");
        return 1;
    }
    
    do {
        printf("digite o codigo do produto: ");
        scanf("%d", &p.codigo);
        
        if (codigo_existe(arquivo, p.codigo)) {
            printf("codigo ja existe\n");
            continue;
        }
        
        printf("digite a descricao do produto: ");
        scanf(" %49[^\n]", p.descricao);
        getchar();
        
        printf("preco: ");
        scanf("%f", &p.preco);
        getchar();
        
        fprintf(arquivo, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
        fflush(arquivo);
        
        printf("digite 1 para cadastra outro produto");
        scanf("%d", &continuar);
        getchar();
        
    } while(continuar == 1);

  while (fscanf(arquivo, "%d %[^\n] %f", &p.codigo, p.descricao, &p.preco) != EOF) {
        p.preco = p.preco * 1.15;
        fprintf(temp, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
    }
    fclose(arquivo);
    
    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");
    return 0;
}
