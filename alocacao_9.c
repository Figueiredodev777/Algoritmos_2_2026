#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* inverter_string(char* texto) 
    {
    
    int tamanho = strlen(texto);
    char* invertida = (char*)malloc(tamanho + 1);
    
    for (int i = 0; i < tamanho; i++) {
        invertida[i] = texto[tamanho - 1 - i];
    }
    invertida[tamanho] = '\0';
    
    return invertida;
    
        
    }

int main() {
    char texto[100];
    
    printf("digite uma palavra: ");
    fgets(texto, 100, stdin);
    
    
    texto[strcspn(texto, "\n")] = '\0';
    
    char* resultado = inverter_string(texto);
    
    
    printf("invertida: %s\n", resultado);
    
    free(resultado); 
    return 0;
}
