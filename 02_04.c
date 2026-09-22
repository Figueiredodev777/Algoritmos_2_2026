#include <stdio.h>

int main() {
   
    float matriz[3][3];
    
    printf("Endereços de memória da matriz 3x3:\n\n");
    
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            printf("matriz[%d][%d]: %p\n", i, j, (void*)&matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
