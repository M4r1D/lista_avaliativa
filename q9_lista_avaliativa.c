#include <stdio.h>
#include <locale.h>
int main(){
    int i, j, abacaxi=0, maca=0, pera=0, VA, VM, VP;
    printf("|    Lista Frutas        |\n");
    printf("|    Abacaxi 5,00 UN     |\n");
    printf("|    Maca 1,00 UN        |\n");
    printf("|    Pera 4,00 UN        |\n");
    printf("\n");
    for(j=0;j<3;j++){
        printf("Pressione 1 - se quer abacaxi\n Pressione 2 - se quer maca\n Pressione 3 - se quer pera\n Pressione 0 - para nenhuma das alternativas:");
        scanf("%d", &i);
    if(i==1){
        printf("Informe a quantidade de abacaxis que voce deseja:");
        scanf("%d", &abacaxi);
        }
    if(i==2){
        printf("Informe a quantidade de macas que voce deseja:");
        scanf("%d", &maca);
        }
    if(i==3){
        printf("Informe a quantidade de peras que voce deseja:");
        scanf("%d", &pera);
        }
    if(i==0){
        }
    }
    VA = 5*abacaxi;
    VM = 1*maca;
    VP = 4*pera;
    printf("Valor total da compra eh:%d\n", VA+VM+VP);

return 0;
}