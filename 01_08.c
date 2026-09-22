#include <stdio.h>

int funcao(int n){

  int soma = 0;
  
  if (n <= 0) {
        return 0; 
}
  for(int i = 1; i < n; i++){

    soma+= i+1;
    
  }
  return soma;
}

int main(){

int n;
  printf("Digite um valor para n\n");
  scanf("%d", &n);
  int resultado = funcao(n);

  printf("o valor e: %d", resultado);
}
