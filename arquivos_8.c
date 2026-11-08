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
    
    char nome_busca[100];
    char linha[500];
    int encontrou = 0;
    
    printf("Digite o nome do cliente para buscar: ");
    scanf("%99[^\n]", nome_busca);
    getchar();
    
    arquivo = fopen("recebimento.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de recebimentos!\n");
        printf("Nenhum recebimento cadastrado.\n");
        return 1;
    }
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome_arquivo[100];
        
        if (sscanf(linha, "Nome do Cliente: %99[^|]", nome_arquivo) == 1) {
            
            int tam = strlen(nome_arquivo);
            while (tam > 0 && nome_arquivo[tam-1] == ' ') {
                nome_arquivo[tam-1] = '\0';
                tam--;
            }
            
           
            if (strcmp(nome_arquivo, nome_busca) == 0) {
                encontrou = 1;
                
               
                char *ptr = strstr(linha, "Valor a ser recebido:");
                if (ptr != NULL) {
                    sscanf(ptr, "Valor a ser recebido: %f", &valor);
                }
                
                ptr = strstr(linha, "Vencimento:");
                if (ptr != NULL) {
                    sscanf(ptr, "Vencimento: %d/%d/%d", &dia_venc, &mes_venc, &ano_venc);
                }
                
                ptr = strstr(linha, "Dias de atraso:");
                if (ptr != NULL) {
                    sscanf(ptr, "Dias de atraso: %d", &dias_atraso);
                }
                
                printf("\nCliente: %s\n", nome_arquivo);
                printf("Valor: R$ %.2f\n", valor);
                printf("Data de Vencimento: %02d/%02d/%d\n", dia_venc, mes_venc, ano_venc);
                printf("Dias em Atraso: %d\n", dias_atraso);
               
            }
        }
    }
    
    fclose(arquivo);
    
    if (!encontrou) {
        printf("\nNenhum recebimento encontrado para o cliente: %s\n", nome_busca);
    }
    
    return 0;
}
