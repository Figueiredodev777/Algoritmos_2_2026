#include <stdio.h>

int main() {
    int a, *b, **c, ***d;
    
    
    printf("Digite um valor para a: ");
    scanf("%d", &a);
    
    
    b = &a;     
    c = &b;     
    d = &c;    
    
    
    printf("Valor de a: %d\n", a);
    printf("Dobro: %d\n", *b * 2);
    printf("Triplo: %d\n", **c * 3);
    printf("Quadruplo: %d\n", ***d * 4);
    
    return 0;
}
