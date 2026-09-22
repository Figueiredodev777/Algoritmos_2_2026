#include <stdio.h>

void extrair_estatisticas(int *vetor, int tamanho, int *min, int *max, float *media)
{
    int *p = vetor;
    int soma = 0;

    *min = *p;
    *max = *p;

    while (p < vetor + tamanho)
    {
        if (*p < *min)
        {
            *min = *p;
        }

        if (*p > *max)
        {
            *max = *p;
        }

        soma += *p;
        p++;
    }

    *media = soma / tamanho;
}

int main()
{
    int vetor[] = {10, 5, 20, 8, 15};
    int tamanho = 5;

    int min;
    int max;
    float media;

    extrair_estatisticas(vetor, tamanho, &min, &max, &media);

    printf("Menor valor: %d\n", min);
    printf("Maior valor: %d\n", max);
    printf("Media: %.2f\n", media);

    return 0;
