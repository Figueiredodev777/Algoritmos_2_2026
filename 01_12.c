#include <stdio.h>

void tabuada(int N) {
    if (N <= 0) {
        printf("Por favor, digite um valor positivo maior que zero.\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        printf("%d x %d = %d\n", i, N, i * N);
    }
}

int main() {
    int N;

    printf("Digite o valor de N: ");
    scanf("%d", &N);

  
    tabuada(N);

    return 0;
}
