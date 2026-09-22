#include <stdio.h>

int main(){
    
    int a, b;
    int *pa, *pb;
    
    pa = &a;
    pb = &b;
    
    printf("Escreva algo para a:\n");
    scanf("%d", &a);
    
    printf("Escreva algo para b:\n");
    scanf("%d", &b);
    
    
    printf("%d\n", a);
    printf("%d\n", b);
    
        if(pa > pb)
        {
        
            printf("%c\n", pa);
    
            
        }else{
            
            printf("%c\n", pb);
            
        }
    
    
        return 0;
}
