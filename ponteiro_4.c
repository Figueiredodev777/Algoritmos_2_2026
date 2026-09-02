
#include <stdio.h>
/*-Você deve criar dois ponteiros locais dentro da função: um inicio apontando
para o primeiro elemento e um fim apontando para o último.
Faça um laço onde o inicio avança (++) e o fim recua (--) trocando os valores de
lugar até que os ponteiros se cruzem no meio do vetor. Não utilize variáveis
inteiras como índice.*/


void inverter(int *vetor, int tamanho)
{
    int *inicio = vetor;
    int *fim = vetor + tamanho - 1;
    int temp;

    while (inicio < fim)
    {
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}


int main() {
    
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = 5;
    int *p;

    printf("vetor original: ");

    for (p = vetor; p < vetor + tamanho; p++)
    {
        printf("%d ", *p);
    }

    inverter(vetor, tamanho);

    printf("vetor invertido: \n");

    for (p = vetor; p < vetor + tamanho; p++)
    {
        printf("%d ", *p);
    }

    return 0;
}
