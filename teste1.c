#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nome{
	char nome[80];
};
//prototipação
void ordenar(struct Nome nomes[]);
void listar(struct Nome nomes[]);

int main(){
	int i, j, k;
	char aux;
	struct Nome nomes[5];
	
	printf("Digite 5 nomes:\n");
	for(i=0;i<5;i++){
		printf("Nome %d:\n", i);
		scanf("%[^\n]s", &nomes[i].nome);
		fflush(stdin);
	}

	//Ordenação
	
//	listar(nomes);
//	printf("\n---------\n");
	ordenar(nomes);
	//printf("\n---------\n");
//	listar(nomes);
	
	
return 0;
}

void listar(struct Nome nomes[]){
	int i=0;
	for(i=0;i<5;i++){
		printf("Nome %d: %s\n", i, nomes[i].nome);
	}			
}


void ordenar(struct Nome nomes[]){
	int i, j, k;
	char aux[30];
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(strcmp(nomes[i].nome,nomes[j].nome)>0){
				strcpy(aux, nomes[i].nome);
		     	strcpy(nomes[i].nome, nomes[j].nome);
		    	strcpy(nomes[j].nome , aux);	
		}
	}			
}
}

/*
struct produto...{1
	char nome[80],
}


int main(){

	Produto produtos[5];
	...

}

void ordenar(Produto produtos[]){

for
	pf...produtos[i].nome;
}

*/
