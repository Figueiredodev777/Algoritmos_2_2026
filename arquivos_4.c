#include <stdio.h>
#include <string.h>

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


void cadastrarClientes() {
    struct Clientes cliente;
    FILE *arquivo;
    int resposta;
    
    arquivo = fopen("cadastro.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    do {
        printf("digite o codigo do cliente\n");
        scanf("%d", &cliente.Cod_Cli);
        getchar();
        
        printf("digite o Nome do cliente\n");
        scanf("%99[^\n]", cliente.Nome);
        getchar();
        
        printf("digite o endereco do cliente\n");
        scanf("%99[^\n]", cliente.Enderco);
        getchar();
        
        printf("digite o telefone do cliente\n");
        scanf("%d", &cliente.Fone);
        getchar();
        
        fprintf(arquivo, "%d|%s|%s|%d\n", cliente.Cod_Cli, cliente.Nome, cliente.Enderco, cliente.Fone);
        
        printf("deseja cadastrar outro cliente? digite 1 para continuar e 0 para sair: ");
        scanf("%d", &resposta);
        getchar();
        
    } while(resposta == 1);
    
    fclose(arquivo);
    printf("Clientes cadastrados com sucesso!\n");
}


void recebibentos() {
    struct recebimentos recebimento;
    FILE *arquivo;
    int resposta;
    
    arquivo = fopen("recebimentos.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao criar arquivo de recebimentos!\n");
        return;
    }
    
    do {
        printf("digite o numero do documento do cliente\n");
        scanf("%d", &recebimento.Num_doc);
        getchar();
        
        printf("digite o valor do documento do cliente\n");
        scanf("%99[^\n]", recebimento.Valor_doc);
        getchar();
        
        printf("digite a data de emissao do documento (dia mes ano): ");
        for(int i = 0; i < 3; i++) {
            scanf("%d", &recebimento.Data_emissao[i]);
        }
        getchar();
        
        printf("digite a data de vencimento do documento (dia mes ano): ");
        for(int j = 0; j < 3; j++) {
            scanf("%d", &recebimento.Data_Vencimento[j]);
        }
        getchar();
        
        printf("digite o codigo do cliente: ");
        scanf("%d", &recebimento.Cod_Cli2);
        getchar();
        
        fprintf(arquivo, "%d|%s|%d/%d/%d|%d/%d/%d|%d\n", 
                recebimento.Num_doc, 
                recebimento.Valor_doc, 
                recebimento.Data_emissao[0], recebimento.Data_emissao[1], recebimento.Data_emissao[2],
                recebimento.Data_Vencimento[0], recebimento.Data_Vencimento[1], recebimento.Data_Vencimento[2],
                recebimento.Cod_Cli2);
        
        printf("deseja cadastrar outro recebimento? digite 1 para continuar e 0 para sair: ");
        scanf("%d", &resposta);
        
    } while(resposta == 1);
    
    fclose(arquivo);

}


void excluir() {
    int codigoExcluir;
    FILE *arquivoClientes, *tempClientes;
    FILE *arquivoRecebimentos, *tempRecebimentos;
    struct Clientes cliente;
    struct recebimentos recebimento;
    int encontrou = 0;
    int recebimentosExcluidos = 0;
    
    printf("Digite o codigo do cliente que deseja excluir: ");
    scanf("%d", &codigoExcluir);
    
    
    arquivoClientes = fopen("cadastro.txt", "r");
    tempClientes = fopen("temp_clientes.txt", "w");
    
    if (arquivoClientes == NULL || tempClientes == NULL) {
        printf("Erro ao abrir arquivos de clientes!\n");
        return;
    }
    
    while (fscanf(arquivoClientes, "%d \n%99[^|]\n%99[^|]\n%d", 
                  &cliente.Cod_Cli, cliente.Nome, cliente.Enderco, &cliente.Fone) != EOF) {
        
        if (cliente.Cod_Cli != codigoExcluir) {
            fprintf(tempClientes, "%d\n%s\n%s\n%d\n", 
                    cliente.Cod_Cli, cliente.Nome, cliente.Enderco, cliente.Fone);
        } else {
            encontrou = 1;
            printf("Cliente excluido: %s\n", cliente.Nome);
        }
    }
    
    fclose(arquivoClientes);
    fclose(tempClientes);
    
    
    arquivoRecebimentos = fopen("recebimentos.txt", "r");
    if (arquivoRecebimentos != NULL) {
        tempRecebimentos = fopen("temp_recebimentos.txt", "w");
        
        if (tempRecebimentos != NULL) {
            while (fscanf(arquivoRecebimentos, "%d|%99[^\n]|%d/%d/%d|%d/%d/%d|%d", 
                          &recebimento.Num_doc, 
                          recebimento.Valor_doc,
                          &recebimento.Data_emissao[0], &recebimento.Data_emissao[1], &recebimento.Data_emissao[2],
                          &recebimento.Data_Vencimento[0], &recebimento.Data_Vencimento[1], &recebimento.Data_Vencimento[2],
                          &recebimento.Cod_Cli2) != EOF) {
                
                if (recebimento.Cod_Cli2 != codigoExcluir) {
                    fprintf(tempRecebimentos, "%d|%s|%d/%d/%d|%d/%d/%d|%d\n", 
                            recebimento.Num_doc, recebimento.Valor_doc,
                            recebimento.Data_emissao[0], recebimento.Data_emissao[1], recebimento.Data_emissao[2],
                            recebimento.Data_Vencimento[0], recebimento.Data_Vencimento[1], recebimento.Data_Vencimento[2],
                            recebimento.Cod_Cli2);
                } else {
                    recebimentosExcluidos++;
                }
            }
            fclose(tempRecebimentos);
        }
        fclose(arquivoRecebimentos);
    }
    
   
    remove("cadastro.txt");
    rename("temp_clientes.txt", "cadastro.txt");
    
    if (arquivoRecebimentos != NULL) {
        remove("recebimentos.txt");
        rename("temp_recebimentos.txt", "recebimentos.txt");
    }
    
    if (encontrou) {
        printf("Cliente excluido com sucesso!\n");
        printf("Recebimentos excluidos: %d\n", recebimentosExcluidos);
    } else {
        printf("Cliente nao encontrado!\n");
        remove("temp_clientes.txt");
        if (tempRecebimentos != NULL) remove("temp_recebimentos.txt");
    }
}

int main() {
    int opcao;
    
    do {
    
        printf("digite 1 para cadastrar clientes\n");
        printf("digite 2 para cadastrar recebiemntos\n");
        printf("digite 3 para excluir \n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        switch(opcao) {
            case 1:
                cadastrarClientes();
                break;
            case 2:
                recebibentos();
                break;
            case 3:
                excluir();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        
    } while(opcao != 0);
    
    return 0;
  //ate hj esse foi o codigo mais dificil da minha vida
}
