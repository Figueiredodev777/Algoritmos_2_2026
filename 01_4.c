#include <stdio.h>


int converter_para_dias(int anos, int meses, int dias) 
{
    int total_dias = (anos * 365) + (meses * 30) + dias;
    return total_dias;
}

int main() {
    int anos, meses, dias;

    printf("Digite a idade em anos, meses e dias:\n");
    printf("Anos: ");
    scanf("%d", &anos);
    printf("Meses: ");
    scanf("%d", &meses);
    printf("Dias: ");
    scanf("%d", &dias);

    int total = converter_para_dias(anos, meses, dias);

    printf("A idade total expressa apenas em dias e: %d dias.\n", total);

    return 0;
}
