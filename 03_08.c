#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct datas{
    
    int dia;
    int mes;
    int ano;
    
};

int main(){
    
    struct datas data[2];
    
    int *pa, *pb, *pc, *pd, *pe, *pf;
   
    pa = &data[0].dia;
    pb = &data[1].dia;
    pc = &data[0].mes;
    pd = &data[1].mes;
    pe = &data[0].ano;
    pf = &data[1].ano;
    
    for(int i = 0; i < 2; i++){
        
        printf("digite o dia: \n");
        scanf("%d", &data[i].dia);
        
        if(data[i].dia > 31)
        {
            
            printf("data invalida;");
        }
        
        printf("digite o mes: \n");
        scanf("%d", &data[i].mes);
        
        if(data[i].mes > 12)
        {
            
            printf("data invalida");
        }
        
        printf("digite o mes: \n");
        scanf("%d", &data[i].ano);
    

        
    }
    
    int dias = abs(pa - pb);
    int meses = abs(pc - pd) * 30;
    int anos = abs(pe - pf) * 365;
    
    int resultado = dias + meses + anos;
    
    printf("A diferenca entre as datas sao: %d", resultado);
}
