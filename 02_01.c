#include <stdio.h>

int main(){
    
    int a = 10; 
    int b = 8;
    int *pa, *pb;
    
    pa = &a;
    pb = &b;
    
    printf("%d\n", a);
    printf("%d\n", a);
    
        if(pa > pb)
        {
        
            printf("%p\n", pa);
    
            
        }
        else
        {
            
            printf("%p", pb);
            
        }
    
    
        return 0;
}
