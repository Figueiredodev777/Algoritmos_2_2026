#include <stdio.h>
#include <math.h>



void calcular_esfera(float raio, float *area, float *volume){

*area = 4 * 3.14 * (raio * raio);
*volume = (4 / 3) * 3.14 * (raio * raio * raio);


}


int main(){

    float r, a, v;
    
    
    printf("digite o raio \n");
    scanf("%f", &r);

    calcular_esfera(r, &a, &v);
    
    printf("Area: %2.f \n", a);
    printf("Volume: %2.f \n", v);

}
