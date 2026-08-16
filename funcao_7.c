#include <stdio.h>

float calcular_media() {
    float valor, soma = 0.0f;
    int quantidade = 0;

    printf("Digite valores positivos (digite 0 ou um numero negativo para parar):\n");

    while (1) {
        scanf("%f", &valor);

       
        if (valor <= 0) {
            break;
        }

        soma += valor;
        quantidade++;
    }

    if (quantidade == 0)
    {
        printf("Nenhum valor positivo foi inserido.\n");
        return 0.0f;
    }

    return soma / quantidade;
}

int main() {
    float media = calcular_media();

    if (media > 0) {
        printf("\nA media aritmetica dos valores digitados e: %.2f\n", media);
    }

    return 0;
}
