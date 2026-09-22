#include <stdio.h>
#include <math.h>

void funcao_baskara(float a, float b, float c) {
    
    if (a == 0) {
        printf("Valor invalido para 'a' (nao e equacao do 2o grau).\n");
        return;
    }

    float delta = b * b - 4 * a * c;

   
    if (delta < 0) {
        printf("A equacao nao possui raizes reais (Delta = %.2f < 0).\n", delta);
    } 
    else {
        float x1 = ((-b) + sqrt(delta)) / (2 * a);
        float x2 = ((-b) - sqrt(delta)) / (2 * a);

        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
} 

int main() {
    float a, b, c;

    printf("Digite os valores para A, B e C: ");
    scanf("%f %f %f", &a, &b, &c);

    
    funcao_baskara(a, b, c);

    return 0;
}
