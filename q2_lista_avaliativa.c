#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c,d,distancia=0;
    printf("digite o valor do eixo x do ponto R:\n");
    scanf("%d", &a);
    fflush(stdin);
    printf("digite o valor do eixo y do ponto R:\n");
    scanf("%d", &b);
    fflush(stdin);
    printf("digite o valor do eixo x do ponto S:\n");
    scanf("%d", &c);
    fflush(stdin);
    printf("digite o valor do eixo y do ponto S:\n");
    scanf("%d", &d);
    fflush(stdin);
    distancia=sqrt(pow(b-a,2)+pow(d-c,2));
    printf("resposta:%.4f\n", distancia);
return 0;
}