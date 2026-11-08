#include <stdio.h>

int main() {
    FILE *arquivo;
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de recebimentos!\n");
        printf("Nenhum recebimento cadastrado.\n");
        return 1;
    }
    
    arquivo = fopen("estilistas.txt", "w");
    fprintf(arquivo, "1;Carlos Silva;3500.00\n");
    fprintf(arquivo, "2;Ana Santos;4200.50\n");
    fprintf(arquivo, "3;Pedro Costa;3800.75\n");
    fclose(arquivo);
    
  
    arquivo = fopen("estacoes.txt", "w");
    fprintf(arquivo, "1;Primavera\n");
    fprintf(arquivo, "2;Verão\n");
    fprintf(arquivo, "3;Outono\n");
    fprintf(arquivo, "4;Inverno\n");
    fclose(arquivo);
    
    arquivo = fopen("roupas.txt", "w");
    fprintf(arquivo, "1;Vestido Floral;1;1;2024\n");
    fprintf(arquivo, "2;Biquini Estampado;2;2;2024\n");
    fprintf(arquivo, "3;Casaco de Lã;3;4;2023\n");
    fclose(arquivo);
    
    printf("Arquivos criados com sucesso!\n");
    printf("- estilistas.txt\n");
    printf("- estacoes.txt\n");
    printf("- roupas.txt\n");
    
    return 0;
}
