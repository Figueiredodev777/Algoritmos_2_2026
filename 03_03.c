#include <stdio.h>
#include <string.h>

struct Materia
{
    int Matricula[5];
    char Aluno[5][50];
    float notas[5][3];
};

int main()
{
    struct Materia aluno;
    
    for(int i = 0; i < 5; i++ ){
        
        printf("Digite o numero da matricula dos 5 alunos: \n");
        scanf("%d", &aluno.Matricula[i]);
        getchar();

    }
    
    for(int j = 0; j < 5; j++){
        
        printf("Digite o nome dos 5 alunos: \n");
        scanf("%49[^\n]", aluno.Aluno[j]);
        getchar();
    }
    
    for(int i = 0; i < 5; i++) {
        printf("\nNotas do aluno %s (matricula %d):\n", aluno.Aluno[i], aluno.Matricula[i]);
        for(int j = 0; j < 3; j++) {
            printf("Digite a nota %d: ", j + 1);
            scanf("%f", &aluno.notas[i][j]);
        }
    }
    
    for(int i = 0; i < 5; i++) {
    float somaAluno = 0;
    for(int j = 0; j < 3; j++) {
        somaAluno += aluno.notas[i][j];
   
    float mediaAluno = somaAluno / 3;
    }
    
    
    }

    float maiorNota = aluno.notas[0][0];
int alunoMaiorNota = 0, provaMaiorNota = 0;

for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 3; j++) {
        if(aluno.notas[i][j] > maiorNota) {
            maiorNota = aluno.notas[i][j];
            alunoMaiorNota = i;
            provaMaiorNota = j;
        }
    }
}
    
    printf("Aluno: %s (Media: %.1f)\n", aluno.Aluno[alunoMaiorNota], maiorNota);
    
    
}
    
    
