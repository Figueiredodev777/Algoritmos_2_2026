#include <stdio.h>

int main(){
    
    int valor[5];
    int *pa;
    pa = &valor[0];
        
    for(int i = 0; i < 5; i++)
    {
        
        scanf("%d", &valor[i]);
        
    }
    for(int j = 0; j < 5; j++)
    {
        printf("%d:", *pa++ * 2);
        
    }
}
