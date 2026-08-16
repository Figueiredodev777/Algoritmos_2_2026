#include <stdio.h>

void triangulo(float x, float y, float z) {
   
    if (x < y + z && y < x + z && z < x + y) {
        
        if (x == y && y == z) {
            printf("Triangulo Equilatero\n");
        } else if (x == y || x == z || y == z) {
            printf("Triangulo Isosceles\n");
        } else {
            printf("Triangulo Escaleno\n");
        }
    } else {
        printf("Nao forma um triangulo\n");
    }
}

int main() {
    float a, b, c;
    
    printf("Digite os tres lados do triangulo: ");
    scanf("%f %f %f", &a, &b, &c);
    
    triangulo(a, b, c);
    
    return 0;
}
