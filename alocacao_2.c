#include <stdio.h>

    struct estudante{

    char aluno[100];
    int matricula;
    float notas[3];
  
  };

int main()
{
    
    printf("A estrutura ocupa: %d byte(s)\n", sizeof(struct estudante));

    return 0;
}
