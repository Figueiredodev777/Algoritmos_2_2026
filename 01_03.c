#include <stdio.h>


void converter_tempo(int total_segundos) {
    if (total_segundos < 0) {
        printf("insira um tempo valido, maior ou igual a zero.\n");
        return;
    }

    int horas = total_segundos / 3600;
    int resto = total_segundos % 3600;
    int minutos = resto / 60;
    int segundos = resto % 60;

    printf("%d segundo(s) equivalem a: %d hora(s), %d minuto(s) e %d segundo(s).\n", 
           total_segundos, horas, minutos, segundos);
}

int main() {
    int tempo_segundos;

    printf("Digite o tempo de duracao em segundos: ");
    scanf("%d", &tempo_segundos);

    
    converter_tempo(tempo_segundos);

    return 0;
}
