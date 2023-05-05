#include <stdio.h>
int main(){
    int i;
    float r,r2, r3, area=0.0, volume=0.0;
    float pi =3.14159;
    printf("digite o valor do raio da esfera:");
    scanf("%f", &r);
    r3=r*r*r;
    r2=r*r;
    printf("valor r:%f\n", r3);
    volume=4/3.0*pi*r3;
    printf("valor do volume da esfera:%4.f\n", volume);
    printf("valor r:%f\n",r2);
    area= 4*pi*r2;
    printf("valor da area da esfera eh:%f\n", area);
return 0;
}