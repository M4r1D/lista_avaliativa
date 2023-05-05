#include <stdio.h>
int main(){
    int a,b,c,d,diferenca=0;
    printf("digite valor de a:\n");
    scanf("%d", &a);
    fflush(stdin);
    printf("digite valor de b:\n");
    scanf("%d", &b);
    fflush(stdin);
    printf("digite valor de c:\n");
    scanf("%d", &c);
    fflush(stdin);
    printf("digite valor de d:\n");
    scanf("%d", &d);
    fflush(stdin);
    diferenca=((a*b)-(c*d));
    printf("Diferenca = (%d*%d - %d*%d)\n",a,b,c,d);
    printf("Diferenca = %d", diferenca);
return 0;
}