#include <stdio.h>

struct Clientes{
    
    int Cod_Cli;
    char Nome[100];
    char Enderco[100];
    int Fone;
    
};

struct recebimentos{
    
    int Num_doc;
    char Valor_doc[100];
    int Data_emissao[3];
    int Data_Vencimento[3];
    int Cod_Cli2;
};
int main()
{
    struct Clientes cliente;
    FILE *arquivo;
    struct recebimentos recebimento;
    int resposta;
    arquivo = fopen("cadastro.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de recebimentos!\n");
        return 1;
    }
    
    
    printf("digite o codigo do cliente\n");
    scanf("%d", &cliente.Cod_Cli);
    getchar();
    
    printf("digite o Nome do cliente\n");
    scanf("%99[^\n]", cliente.Nome);
    getchar();
    
    printf("digite o endercoo do cliente\n");
    scanf("%99[^\n]", cliente.Enderco);
    getchar();
    
    printf("digite o telefone do cliente\n");
    scanf("%d", &cliente.Fone);
    getchar();
    
    fprintf(arquivo, "Codigo do CLiente: %d\nNome: %s\nEnderco do cliente: %s\nTelefone do cliente: %d\n", cliente.Cod_Cli, cliente.Nome, cliente.Enderco, cliente.Fone);
    
    
    
   
    
    
    fclose(arquivo);
    return 0;
}

    
