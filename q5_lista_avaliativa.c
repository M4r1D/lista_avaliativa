#include <stdio.h>
int main(){
    int x,i;
    printf("digite um valor:\n");
    scanf("%d", &x);
    for(i=1;i<=100;i++){
        if(x % i == 0){
            printf("-%d\n", i);
        }
    }
return 0;
}