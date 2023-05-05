#include <stdio.h>
int main(){
    float x,y;
    printf("digite um valor:\n");
    scanf("%f", &x);
    fflush(stdin);
    printf("digite um valor:\n");
    scanf("%f", &y);
    fflush(stdin);
    printf("As coordenadas do ponto eh:(%.1f,%.1f)\n",x,y);
    if(x==0 && y==0){
        printf("Origem.\n");
    }
    if(x==0 && y!=0){
        printf("Eixo Y");
    }
    if(y==0 && x!=0){
        printf("Eixo X");
    }
    if(x>0 && y>0){
        printf("Pertence ao primeiro quadrante.\n");
    }
    if(x<0 && y>0){
        printf("Pertence ao segugundo quadrante.\n");
    }
    if(x<0 && y<0){
        printf("Pertence ao terceiro quadrante.\n");
    }
    if(x>0 && y<0){
        printf("Pertence ao quarto quadrante.\n");
    }
return 0;
}