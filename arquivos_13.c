#include <stdio.h>
#include <string.h>

#define max 100

typedef struct {
    int codigo;
    char nome[50];
} estacao;

typedef struct {
    int codigo;
    char nome[50];
    float salario;
} estilista;

typedef struct {
    int codigo;
    char descricao[100];
    int cod_estilista;
    int cod_estacao;
    int ano;
} roupa;

estacao estacoes[max];
estilista estilistas[max];
roupa roupas[max];

int num_estacoes = 0;
int num_estilistas = 0;
int num_roupas = 0;

void cadastrar_estacao() {
    if (num_estacoes >= max) {
        printf("limite de estacoes atingido\n");
        return;
    }
    
    estacoes[num_estacoes].codigo = num_estacoes + 1;
    
    printf("nome da estacao: ");
    scanf(" %[^\n]", estacoes[num_estacoes].nome);
    
    printf("estacao cadastrada com codigo %d\n", estacoes[num_estacoes].codigo);
    num_estacoes++;
}

void cadastrar_estilista() {
    if (num_estilistas >= max) {
        printf("limite de estilistas atingido\n");
        return;
    }
    
    estilistas[num_estilistas].codigo = num_estilistas + 1;
    
    printf("nome do estilista: ");
    scanf(" %[^\n]", estilistas[num_estilistas].nome);
    
    printf("salario: ");
    scanf("%f", &estilistas[num_estilistas].salario);
    
    printf("estilista cadastrado com codigo %d\n", estilistas[num_estilistas].codigo);
    num_estilistas++;
}

void cadastrar_roupa() {
    if (num_roupas >= max) {
        printf("limite de roupas atingido\n");
        return;
    }
    
    if (num_estacoes == 0 || num_estilistas == 0) {
        printf("cadastre estacoes e estilistas primeiro\n");
        return;
    }
    
    roupas[num_roupas].codigo = num_roupas + 1;
    
    printf("descricao da roupa: ");
    scanf(" %[^\n]", roupas[num_roupas].descricao);
    
    printf("ano: ");
    scanf("%d", &roupas[num_roupas].ano);
    
    printf("estacoes disponiveis:\n");
    for (int i = 0; i < num_estacoes; i++) {
        printf("%d - %s\n", estacoes[i].codigo, estacoes[i].nome);
    }
    printf("codigo da estacao: ");
    scanf("%d", &roupas[num_roupas].cod_estacao);
    
    printf("estilistas disponiveis:\n");
    for (int i = 0; i < num_estilistas; i++) {
        printf("%d - %s\n", estilistas[i].codigo, estilistas[i].nome);
    }
    printf("codigo do estilista: ");
    scanf("%d", &roupas[num_roupas].cod_estilista);
    
    printf("roupa cadastrada com codigo %d\n", roupas[num_roupas].codigo);
    num_roupas++;
}

void relatorio_estacao() {
    if (num_roupas == 0) {
        printf("nenhuma roupa cadastrada\n");
        return;
    }
    
    printf("estacoes disponiveis:\n");
    for (int i = 0; i < num_estacoes; i++) {
        printf("%d - %s\n", estacoes[i].codigo, estacoes[i].nome);
    }
    
    int cod_estacao;
    printf("digite o codigo da estacao: ");
    scanf("%d", &cod_estacao);
    
    printf("roupas da estacao:\n");
    int encontrou = 0;
    
    for (int i = 0; i < num_roupas; i++) {
        if (roupas[i].cod_estacao == cod_estacao) {
            char nome_estilista[50] = "nao encontrado";
            for (int j = 0; j < num_estilistas; j++) {
                if (estilistas[j].codigo == roupas[i].cod_estilista) {
                    strcpy(nome_estilista, estilistas[j].nome);
                    break;
                }
            }
            
            char nome_estacao[50] = "nao encontrada";
            for (int j = 0; j < num_estacoes; j++) {
                if (estacoes[j].codigo == roupas[i].cod_estacao) {
                    strcpy(nome_estacao, estacoes[j].nome);
                    break;
                }
            }
            
            printf("codigo: %d\n", roupas[i].codigo);
            printf("descricao: %s\n", roupas[i].descricao);
            printf("estacao: %s\n", nome_estacao);
            printf("estilista: %s\n", nome_estilista);
            printf("ano: %d\n", roupas[i].ano);
            printf("---\n");
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("nenhuma roupa encontrada para esta estacao\n");
    }
}

int main() {
    strcpy(estacoes[0].nome, "primavera-verao");
    estacoes[0].codigo = 1;
    strcpy(estacoes[1].nome, "outono-inverno");
    estacoes[1].codigo = 2;
    num_estacoes = 2;
    
    strcpy(estilistas[0].nome, "carlos silva");
    estilistas[0].codigo = 1;
    estilistas[0].salario = 3500.00;
    strcpy(estilistas[1].nome, "ana santos");
    estilistas[1].codigo = 2;
    estilistas[1].salario = 4200.50;
    num_estilistas = 2;
    
    int opcao;
    
    do {
        printf("digite 1 para cadastra estacao\n");
        printf("digite 2 para cadastra estilista\n");
        printf("digite 3 cadastrar roupa\n");
        printf("digite 4 relatorio por estacao\n");
        printf("digite 5 pra sair\n");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrar_estacao();
                break;
            case 2:
                cadastrar_estilista();
                break;
            case 3:
                cadastrar_roupa();
                break;
            case 4:
                relatorio_estacao();
                break;
            case 5:
                printf("saindo\n");
                break;
            default:
                printf("opcao invalida\n");
        }
    } while(opcao != 5);
    
    return 0;
}
