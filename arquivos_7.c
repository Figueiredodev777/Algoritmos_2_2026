#include <stdio.h>
#include <stdlib.h>
int main(){
    int dia_hoje = 15, mes_hoje = 10, ano_hoje = 2025;
    char nome[100];
    float valor;
    int dia_venc, mes_venc, ano_venc;
    int dias_atraso = 0;
    FILE *arquivo;
    
    int resul_ano = 0, resul_mes = 0, resul_dia = 0;
    int dias_atrasado = 0;
    
    arquivo = fopen("recebimento.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de recebimentos!\n");
        return 1;
    }
    
    
    printf("digite o nome do cliente: ");
    scanf("%99[^\n]", nome);
    getchar();
    
    printf("Valor a ser recebido: ");
    scanf("%f", &valor);
    getchar();
    
    printf("digite o dia, mes e ano de vencimento\n");
    scanf("%d %d %d", &dia_venc, &mes_venc, &ano_venc);
    getchar();
    
    
    
     if (ano_venc < ano_hoje) {
        dias_atraso = (ano_hoje - ano_venc) * 365 + (mes_hoje - mes_venc) * 30 + (dia_hoje - dia_venc);
    }
    else if (ano_venc == ano_hoje) {
        if (mes_venc < mes_hoje) {
            dias_atraso = (mes_hoje - mes_venc) * 30 + (dia_hoje - dia_venc);
        }
        else if (mes_venc == mes_hoje && dia_venc < dia_hoje) {
            dias_atraso = dia_hoje - dia_venc;
        }
    }
    
    
    fprintf(arquivo, "Nome do Cliente: %s| Valor a ser recebido: %.2f| Vencimento: %d/%d/%d| Dias de atraso: %d", nome, valor, dia_venc, mes_venc, ano_venc, dias_atraso);
    fclose(arquivo);
    return 0;
}

