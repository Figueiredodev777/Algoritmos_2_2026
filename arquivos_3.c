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
    
    do{
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
    
    //parte dop recebimento=) nao colei do chat gpt é so para eu nao me perder
    printf("digite o numero do docuemnto do cliente\n");
    scanf("%d", &recebimento.Num_doc);
    getchar();
    
    printf("digite o valor do documento do cliente\n");
    scanf("%99[^\n]", recebimento.Valor_doc);
    getchar();
    
    //loop pra pegar as data direito 
    for(int i = 0; i < 3; i++)
    {
    printf("digite a data de emissao do documento do cliente\n");
    scanf("%d", &recebimento.Data_emissao[i]);
    getchar();
    
    }
    
    for(int j = 0; j < 3; j++)
    {
        
        printf("digite a data de vencimento do documento do cliente\n");
        scanf("%d", &recebimento.Data_Vencimento[j]);
        getchar();
        
    }
    
    printf("digite o codigo do cliente para saber se o mesmo ja esta cadastrado\n");
    scanf("%d", &recebimento.Cod_Cli2);
    getchar();
    
    if(cliente.Cod_Cli == recebimento.Cod_Cli2){
        
        printf("Cliente ja cadastrado");
    }
    
    printf("deseja cadastra outro cliente? digite 1 para continuar e 0 para sair.");
    scanf("%d", &resposta);
    }while(resposta == 1);
    
    fprintf(arquivo, "Numero DOC: %d \nValor Doc: %s \nData de emissao: %d/%d/%d \nData de vencimento: %d/%d/%d", recebimento.Num_doc, recebimento.Valor_doc, recebimento.Data_emissao[0], recebimento.Data_emissao[1], recebimento.Data_emissao[2], recebimento.Data_Vencimento[0], recebimento.Data_Vencimento[1], recebimento.Data_Vencimento[2]);
    
    
    fclose(arquivo);
    return 0;
}
