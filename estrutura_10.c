#include <stdio.h>
#include <string.h>

struct Atleta {
    char nome[50];
    char esporte[30];
    int idade;
    float altura;
};

int main() {
    struct Atleta atletas[5];
    struct Atleta temp;

    // Leitura dos dados dos 5 atletas
    for (int i = 0; i < 5; i++) {
        printf("Atleta %d:\n", i + 1);

        printf("Nome: ");
        fgets(atletas[i].nome, 50, stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")] = '\0';

        printf("Esporte: ");
        fgets(atletas[i].esporte, 30, stdin);
        atletas[i].esporte[strcspn(atletas[i].esporte, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &atletas[i].idade);
        getchar();

        printf("Altura (em metros): ");
        scanf("%f", &atletas[i].altura);
        getchar();

        printf("\n");
    }

  
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (atletas[j].idade < atletas[j + 1].idade) {
                temp = atletas[j];
                atletas[j] = atletas[j + 1];
                atletas[j + 1] = temp;
            }
        }
    }

    
    printf("atletas do mais velho pro mais novo:\n");
    for (int i = 0; i < 5; i++) {
        printf("%dº - %s\n", i + 1, atletas[i].nome);
        printf("   Esporte: %s\n", atletas[i].esporte);
        printf("   Idade: %d anos\n", atletas[i].idade);
        printf("   Altura: %.2f m\n\n", atletas[i].altura);
    }

    return 0;
}