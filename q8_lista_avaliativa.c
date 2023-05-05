#include <stdio.h>
int main(){
    int i, maior=0, menor=999;
    while(i>0){
        printf("Se quiser sair digite um numero negativo!\n");
        printf("Digite um numero:\n");
        scanf("%d", &i);
        if(i>maior){
            maior=i;
        }
        if(i<menor){
            menor=i;
        }
    }
    printf("O maior numero eh:%d\n", maior);
    printf("O menor numero eh:%d\n", menor);
return 0;
}