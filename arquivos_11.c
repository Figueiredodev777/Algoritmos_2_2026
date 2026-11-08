#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int dia_hoje = 15, mes_hoje = 10, ano_hoje = 2025;
    char nome[100];
    float valor;
    int dia_venc, mes_venc, ano_venc;
    int dias_atraso = 0;
    FILE *arquivo;
    
    int resul_ano = 0, resul_mes = 0, resul_dia = 0;
    int dias_atrasado = 0;
    
    float valor_minimo, valor_maximo;
    char linha[500];
    int encontrou = 0;
    int total_registros = 0;
    
    printf("digite o valor minimo: R$ ");
    scanf("%f", &valor_minimo);
    getchar();
    
    printf("digite o valor maximo: R$ ");
    scanf("%f", &valor_maximo);
    getchar();
    
    arquivo = fopen("recebimento.txt", "r");
    if (arquivo == NULL) {
        printf("erro ao abrir arquivo de recebimentos!\n");
        printf("nenhum recebimento cadastrado.\n");
        return 1;
    }
    
    printf("\nrecebimentos entre R$ %.2f e R$ %.2f", valor_minimo, valor_maximo);
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome_arquivo[100];
        float valor_arquivo;
        int dia_venc_arquivo, mes_venc_arquivo, ano_venc_arquivo;
        int dias_atraso_arquivo;
        
        if (sscanf(linha, "Nome do Cliente: %99[^|]", nome_arquivo) == 1) {
            int tam = strlen(nome_arquivo);
            while (tam > 0 && nome_arquivo[tam-1] == ' ') {
                nome_arquivo[tam-1] = '\0';
                tam--;
            }
            
            char *ptr = strstr(linha, "Valor a ser recebido:");
            if (ptr != NULL) {
                sscanf(ptr, "Valor a ser recebido: %f", &valor_arquivo);
            }
            
            ptr = strstr(linha, "Vencimento:");
            if (ptr != NULL) {
                sscanf(ptr, "Vencimento: %d/%d/%d", &dia_venc_arquivo, &mes_venc_arquivo, &ano_venc_arquivo);
            }
            
            ptr = strstr(linha, "Dias de atraso:");
            if (ptr != NULL) {
                sscanf(ptr, "Dias de atraso: %d", &dias_atraso_arquivo);
            }
            
            if (valor_arquivo >= valor_minimo && valor_arquivo <= valor_maximo) {
                encontrou = 1;
                total_registros++;
                
                printf("\ncliente: %s\n", nome_arquivo);
                printf("valor: R$ %.2f\n", valor_arquivo);
                printf("data de vencimento: %02d/%02d/%d\n", dia_venc_arquivo, mes_venc_arquivo, ano_venc_arquivo);
                printf("dias em atraso: %d\n", dias_atraso_arquivo);
                
            }
        }
    }
    
    fclose(arquivo);
    
    if (!encontrou) {
        printf("\nnenhum recebimento encontrado entre R$ %.2f e R$ %.2f\n", valor_minimo, valor_maximo);
    } else {
        printf("\ntotal de registros encontrados: %d\n", total_registros);
    }
    
    return 0;
}
