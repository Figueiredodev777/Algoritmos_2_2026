#include <stdio.h>

int n_perfeito(int numero) {
    if (numero <= 1) {
        return 0; 
    }

    int soma_divisores = 0;

   
    for (int i = 1; i <= numero / 2; i++) {
        if (numero % i == 0) {
            soma_divisores += i;
        }
    }

    if (soma_divisores == numero) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int valor;

    printf("digite um numero inteiro: ");
    scanf("%d", &valor);

    if (n_perfeito(valor)) {
        printf("%d e um numero perfeito, %d\n", valor, n_perfeito(valor));
    } else {
        printf("%d nao e um numero perfeito, %d\n", valor, n_perfeito(valor));
    }

    return 0;
}
