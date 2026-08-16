#include <stdio.h>


double funcao_9(int N) {
    double soma = 1.0;
    double fatorial = 1.0;

    for (int i = 1; i <= N; i++) {
        fatorial *= i;
        soma += 1.0 / fatorial;
    }

    return soma;
}

int main(void) {
    int N;
    printf("digite um valor para N:");
    scanf("%d", &N);

    int resultado = funcao_9(N);
    printf("S = %.10f\n", funcao_9(N));
    return 0;
}
