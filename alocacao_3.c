#include <stdio.h>
#include <stdlib.h>

struct Cadastro {
    char nome[100];
    int idade;
    char endereco[100];
};

struct Cadastro *criarCadastro(int n) {
    struct Cadastro *cadastros;

    if (n <= 0) {
        return NULL;
    }

    cadastros = (struct Cadastro *)malloc(n * sizeof(struct Cadastro));

    if (cadastros == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("Pessoa %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", cadastros[i].nome);
        getchar();

        printf("Idade: ");
        scanf("%d", &cadastros[i].idade);
        getchar();

        printf("Endereco: ");
        scanf("%s", cadastros[i].endereco);
        getchar();
    }

    return cadastros;
}

int main() {
    int n;
    struct Cadastro *cadastros;

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &n);

    cadastros = criarCadastro(n);

    if (cadastros == NULL) {
        printf("Numero invalido!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Pessoa %d: %s, %d anos, %s\n",
               i + 1,
               cadastros[i].nome,
               cadastros[i].idade,
               cadastros[i].endereco);
    }

    free(cadastros);

    return 0;
}
