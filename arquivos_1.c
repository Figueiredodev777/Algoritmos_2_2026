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
}
