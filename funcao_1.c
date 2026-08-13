#include <stdio.h>

float volume(float raio_r)
    {
        float pi = 3.14;
        float volume = 4.0 / 3.0 * pi * (raio_r * raio_r * raio_r);
        //v = 4/3.P .R3

        return volume;


    }


    int main(){

        float raio_r;
        printf("digite um valor pro raio\n");
        scanf("%f", &raio_r);
        float resultado = volume(raio_r);

        printf("o volume :%f", resultado);


        return 0;


    }
