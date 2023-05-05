#include <stdio.h>
int main(){
    int i,x, proximo, anterior=0, atual=1;
    do{
        printf("digite um valor inteiro maior ou igual a zero:\n");
        scanf("%d", &x);
    } while(x<0);
   
    if (x == 0) {
        printf("O termo de ordem zero da sequencia de Fibonacci eh: 0\n");
        return 0;
    }
    
    if (x == 1) {
        printf("O primeiro termo da sequencia de Fibonacci eh: 1\n");
        return 0;
    }
    
    for (i = 2; i <= x; i++) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    
    printf("O termo de ordem %d da sequencia de Fibonacci eh: %d\n", x, atual);

return 0;
}