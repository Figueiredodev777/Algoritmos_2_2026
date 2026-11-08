#include <stdio.h>

typedef struct {
    int numero;
    char nome[50];
    float nota1;
    float nota2;
} aluno;

int main() {
    FILE *arquivo;
    aluno a;
    int opcao;
    
    do {
        printf("1. criar\n");
        printf("2. incluir\n");
        printf("3. sair\n");
        printf("digite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                arquivo = fopen("alunos.txt", "w");
                if (arquivo == NULL) {
                    printf("erro ao criar arquivo\n");
                } else {
                    printf("arquivo criado\n");
                    fclose(arquivo);
                }
                break;
                
            case 2:
                arquivo = fopen("alunos.txt", "a");
                if (arquivo == NULL) {
                    printf("arquivo nao existe\n");
                } else {
                    printf("numero: ");
                    scanf("%d", &a.numero);
                    printf("nome: ");
                    scanf("%49[^\n]", a.nome);
                    printf("nota1: ");
                    scanf("%f", &a.nota1);
                    printf("nota2: ");
                    scanf("%f", &a.nota2);
                    
                    fprintf(arquivo, "%d %s %.1f %.1f\n", a.numero, a.nome, a.nota1, a.nota2);
                    fclose(arquivo);
                    
                    arquivo = fopen("alunos.txt", "r");
                    printf("\nregistros cadastrados:\n");
                    while(fscanf(arquivo, "%d %[^\n] %f %f", &a.numero, a.nome, &a.nota1, &a.nota2) != EOF) {
                        float media = (a.nota1 + a.nota2) / 2;
                        printf("numero: %d, nome: %s, nota1: %.1f, nota2: %.1f, media: %.1f\n", 
                               a.numero, a.nome, a.nota1, a.nota2, media);
                    }
                    fclose(arquivo);
                }
                break;
                
            case 3:
                printf("saindo\n");
                break;
                
            default:
                printf("opcao invalida\n");
        }
        printf("\n");
    } while(opcao != 3);
    
    return 0;
}
