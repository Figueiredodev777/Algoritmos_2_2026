#include <stdio.h>

float calcular(float n1, float n2, char simbolo) {
    switch (simbolo) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            if (n2 == 0) {
                printf("Erro: Divisao por zero nao permitida!\n");
                return 0.0;
            }
            return n1 / n2;
        default:
            printf("Erro: Símbolo '%c' invalido!\n", simbolo);
            return 0.0;
    }
}

int main() {
    float num1, num2;
    char operacao;

    printf("digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("digite a operacao entre +, -, *, /: ");
    scanf(" %c", &operacao);

    printf("digite o segundo numero: ");
    scanf("%f", &num2);

    float resultado = calcular(num1, num2, operacao);

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
