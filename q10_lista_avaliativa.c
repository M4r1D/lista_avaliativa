#include <stdio.h>
int main(){
    float media,i,valor,total=0;
    for(i=0;i<10;i++){
        printf("digite a sua nota:\n");
        scanf("%f", &valor);
        total += valor;
    }
    media = (total/10);
    printf("A media eh:%f\n", media);
return 0;
}