#include <stdio.h>

typedef struct {
    int codigo;
    char descricao[50];
    float preco;
} produto;

int main() {
    FILE *arquivo;
    produto p;
    
    arquivo = fopen("PRODUTOS.txt", "w");
    
    if (arquivo == NULL) {
        printf("erro ao criar arquivo\n");
        return 1;
    }
    
    
    fclose(arquivo);
    
    return 0;
}
