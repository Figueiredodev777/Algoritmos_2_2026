#include <stdio.h>
#include <math.h>


    struct Retangulo {
        
        //superior esquerdo
        float x;
        float y;
        
        //inferior direito
        float x1;
        float y1;
    };
    
    
int main(){
        
        struct Retangulo ponto;
        
        
    printf("digite a coordenada X_1: ");
    scanf("%f", &ponto.x);
    
    printf("digite a coordenada Y_1: ");
    scanf("%f", &ponto.y); 
    
    printf("digite a coordenada X_2: ");
    scanf("%f", &ponto.x1);
    
    printf("digite a coordenada Y_2: ");
    scanf("%f", &ponto.y1); 
    
    float largura = fabs(ponto.x1 - ponto.x);
    float altura = fabs(ponto.y - ponto.y1);
    float Area = largura * altura;
    float Diagonal = sqrt(largura * largura + altura * altura);
    float perimetro = 2 * (largura + altura);
     
    
    printf("A Area do retangulo: %f \n", Area);
    printf("A Diagonal do retangulo: %f \n", Diagonal);
    printf("A Perimetro do retangulo: %f \n", perimetro);
    
    
        return 0;
    }
