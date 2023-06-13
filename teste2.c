#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50
#define MAX_TELEFONE 11
#define MAX_UF 3

// structs

struct Ordem{
	char nome[80];
};

typedef struct
{
//usar alocaÃ§Ã£o dinÃ¢mica
    char marca[100];
    char site[100];
    char telefone[MAX_TELEFONE];
    char UF[MAX_UF];
} Fabricante;

typedef struct
{
 //usar alocaÃ§Ã£o dinÃ¢mica
    char descricao[100];
    float peso;
    char medida[2];
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    Fabricante fabricante;
} Produto;

//structs 

// funÃ§Ãµes dos relatÃ³rios 

void listarTodasMarcas(Fabricante fabricantes[], int numFabricantes)
{
    printf("\n=== Lista de Marcas ===\n");
    for (int i = 0; i < numFabricantes; i++)
    {
        printf("Marca: %s\n", fabricantes[i].marca);
        printf("Site: %s\n", fabricantes[i].site);
        printf("Telefone: %s\n", fabricantes[i].telefone);
        printf("UF: %s\n", fabricantes[i].UF);
        printf("-----------------------\n");
    }
    printf("========================\n");
}

void listarTodosProdutos(Produto produtos[], int numProdutos)
{
    printf("\n=== Lista de Produtos ===\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$%.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$%.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$%.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("-----------------------\n");
    }
    printf("=========================\n");
}

void listarProdutosPorEstado(Produto produtos[], int numProdutos)
{
    char UF[3];
    printf("Digite o UF do estado: ");
    scanf("%s", UF);

    printf("\n=== Lista de Produtos do Estado %s ===\n", UF);
    int encontrou = 0;
    for (int i = 0; i < numProdutos; i++)
    {
        if (strcmp(produtos[i].fabricante.UF, UF) == 0)
        {
            printf("Descricao: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de Compra: R$%.2f\n", produtos[i].valorCompra);
            printf("Valor de Venda: R$%.2f\n", produtos[i].valorVenda);
            printf("Valor do Lucro: R$%.2f\n", produtos[i].valorLucro);
            printf("Percentual do Lucro: %.2f\n", produtos[i].percentualLucro);
            printf("Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("-----------------------\n");
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhum produto encontrado para o estado %s.\n", UF);
    }
}

void listarProdutosPorMarca(Produto produtos[], int numProdutos)
{
    char marca[100];
    printf("Digite a marca: ");
    scanf(" %[^\n]", marca);

    printf("\n=== Lista de Produtos da Marca %s ===\n", marca);
    int encontrou = 0;
    for (int i = 0; i < numProdutos; i++)
    {
        if (strcmp(produtos[i].fabricante.marca, marca) == 0)
        {
            printf("Descricao: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de Compra: R$%.2f\n", produtos[i].valorCompra);
            printf("Valor de Venda: R$%.2f\n", produtos[i].valorVenda);
            printf("Valor do Lucro: R$%.2f\n", produtos[i].valorLucro);
            printf("Percentual do Lucro: %.2f\n", produtos[i].percentualLucro);
            printf("Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("-----------------------\n");
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhum produto encontrado para a marca %s.\n", marca);
    }
}

void encontrarEstadoProdutoMaisCaro(Produto produtos[], int numProdutos)
{
    float maiorValor = 0;
    char estados[MAX_PRODUTOS][3];
    int numEstados = 0;

    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda > maiorValor)
        {
            maiorValor = produtos[i].valorVenda;
            strcpy(estados[0], produtos[i].fabricante.UF);
            numEstados = 1;
        }
        else if (produtos[i].valorVenda == maiorValor)
        {
            int encontrado = 0;
            for (int j = 0; j < numEstados; j++)
            {
                if (strcmp(estados[j], produtos[i].fabricante.UF) == 0)
                {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                strcpy(estados[numEstados], produtos[i].fabricante.UF);
                numEstados++;
            }
        }
    }

    printf("\n=== Estado(s) onde esta registrado o produto mais caro ===\n");
    for (int i = 0; i < numEstados; i++)
    {
        printf("%s\n", estados[i]);
    }
    printf("==============================\n");
}

void encontrarFabricanteProdutoMaisBarato(Produto produtos[], int numProdutos)
{
    float menorValor = produtos[0].valorVenda;
    char fabricantes[MAX_PRODUTOS][100];
    int numFabricantes = 0;

    for (int i = 1; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda < menorValor)
        {
            menorValor = produtos[i].valorVenda;
            strcpy(fabricantes[0], produtos[i].fabricante.marca);
            numFabricantes = 1;
        }
        else if (produtos[i].valorVenda == menorValor)
        {
            int encontrado = 0;
            for (int j = 0; j < numFabricantes; j++)
            {
                if (strcmp(fabricantes[j], produtos[i].fabricante.marca) == 0)
                {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
            {
                strcpy(fabricantes[numFabricantes], produtos[i].fabricante.marca);
                numFabricantes++;
            }
        }
    }

    printf("\n=== Fabricante(s) onde esta registrado o produto mais barato ===\n");
    for (int i = 0; i < numFabricantes; i++)
    {
        printf("%s\n", fabricantes[i]);
    }
    printf("===============================\n");
}

void listarProdutosPorValor(Produto produtos[], int numProdutos)
{
    // Ordenar produtos por valor de venda em ordem crescente
    for (int i = 0; i < numProdutos - 1; i++)
    {
        for (int j = 0; j < numProdutos - i - 1; j++)
        {
            if (produtos[j].valorVenda > produtos[j + 1].valorVenda)
            {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("\n=== Lista de Produtos em Ordem Crescente de Valor ===\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$%.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$%.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$%.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("-----------------------\n");
    }
    printf("=========================\n");
}

void listarProdutosPorLucro(Produto produtos[], int numProdutos)
{
    // Ordenar produtos por valor de lucro em ordem crescente
    for (int i = 0; i < numProdutos - 1; i++)
    {
        for (int j = 0; j < numProdutos - i - 1; j++)
        {
            if (produtos[j].valorLucro > produtos[j + 1].valorLucro)
            {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("\n=== Lista de Produtos em Ordem Crescente de Maior Valor de Lucro ===\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$%.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$%.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$%.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("-----------------------\n");
    }
    printf("=============================\n");
}

void listarProdutosPorPercentualLucro(Produto produtos[], int numProdutos)
{
    // Ordenar produtos por percentual de lucro em ordem crescente
    for (int i = 0; i < numProdutos - 1; i++)
    {
        for (int j = 0; j < numProdutos - i - 1; j++)
        {
            if (produtos[j].percentualLucro > produtos[j + 1].percentualLucro)
            {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("\n=== Lista de Produtos em Ordem Crescente de Maior Percentual de Lucro ===\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$%.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$%.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$%.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("-----------------------\n");
    }
    printf("===============================\n");
}
//funÃ§Ãµes dos relatÃ³rios

void leValidaPeso(float *peso) {
    do {
        printf("Peso (em gramas): ");
        scanf("%f", peso);
        if (*peso < 50 || *peso > 50000) {
            printf("Peso invÃ¡lido. O peso deve estar entre 50g e 50kg.\n");
        }
    } while (*peso < 50 || *peso > 50000);

    *peso /= 1000; // Converte de gramas para quilos
}

//prototipação
char ordem(struct Ordem alfabeto[]);
char listar(struct Ordem alfabeto[]);


int main()
{
	struct Ordem alfabeto[MAX_PRODUTOS];
	
    float peso;
    
    Fabricante fabricantes[MAX_FABRICANTES];
    Produto produtos[MAX_PRODUTOS];
    int numFabricantes = 0;
    int numProdutos = 0;
    int i=0;
    
    
    

    // Cadastro de fabricantes
    for (i = 0; i < MAX_FABRICANTES; i++)
    {
        printf("\n=== Cadastro de Fabricante %d ===\n", i + 1);
        printf("Marca: ");
        scanf(" %[^\n]s", &fabricantes[i].marca);
        printf("Site: ");
        scanf(" %[^\n]s", &fabricantes[i].site);
        printf("Telefone: ");
        scanf(" %[^\n]s", &fabricantes[i].telefone);
        
        if(strlen(fabricantes[i].telefone)!= MAX_TELEFONE)
        {
			do{	
		printf("O numero que voce digitou nao esta no formato [DDD sem o zero] [numero de telefone] => EX:119XXXXYYYY(sem espacos entre os digitos).\n");
			printf("Digite novamente: ");
        	scanf("%s", &fabricantes[i].telefone);
		}while(strlen(fabricantes[i].telefone)!= MAX_TELEFONE);
}
		printf("UF: ");
        scanf(" %[^\n]s", fabricantes[i].UF);
        numFabricantes++;

if(strlen(fabricantes[i].UF)< 2 || strlen(fabricantes[i].UF)>2 )
        {
			do{	
		printf("A UF que voce digitou nao esta no formato XX => EX: RJ ou rj, DF ou df.\n");
			printf("Digite novamente: ");
        	scanf("%s", &fabricantes[i].UF);
		}while(strlen(fabricantes[i].UF)< 2 || strlen(fabricantes[i].UF)>2 );
}


        printf("Fabricante cadastrado com sucesso!\n");


        char continuar;
        printf("Deseja cadastrar outro fabricante? (S/N): ");
        scanf(" %c", &continuar);
        if (continuar == 'N' || continuar == 'n')
        {
            break;
        }
    
}



    // Cadastro de produtos
    for (i = 0; i < MAX_PRODUTOS; i++)
    {
        printf("\n=== Cadastro de Produto %d ===\n", i + 1);
        printf("Descricao: ");
        scanf(" %[^\n]", produtos[i].descricao);
        fflush(stdin);
        printf("Peso: ");
        scanf("%f", &produtos[i].peso);
        leValidaPeso(&peso);
    // chamar funÃ§Ã£o le_valida_peso
        fflush(stdin);
        printf("Valor de Compra: ");
        scanf("%f", &produtos[i].valorCompra);
    //chamar funÃ§Ã£o le_valida_valorcompra
        fflush(stdin);
        printf("Valor de Venda: ");
        scanf("%f", &produtos[i].valorVenda);
    //chamar funÃ§Ã£o le_valida_valorvenda
        fflush(stdin);

        produtos[i].valorLucro = produtos[i].valorVenda - produtos[i].valorCompra;
        produtos[i].percentualLucro = (produtos[i].valorLucro / produtos[i].valorVenda) * 100;

        // Selecionar fabricante
        printf("Fabricante (Marca): ");
        scanf(" %[^\n]", produtos[i].fabricante.marca);
        fflush(stdin);
        // Procurar o fabricante no vetor de fabricantes
        int fabricanteEncontrado = 0;
        for (int j = 0; j < numFabricantes; j++)
        {
            if (strcmp(produtos[i].fabricante.marca, fabricantes[j].marca) == 0)
            {
                fabricanteEncontrado = 1;
                strcpy(produtos[i].fabricante.site, fabricantes[j].site);
                strcpy(produtos[i].fabricante.telefone, fabricantes[j].telefone);
                strcpy(produtos[i].fabricante.UF, fabricantes[j].UF);
                break;
            }
        }

        if (!fabricanteEncontrado)
        {
            printf("Fabricante nao encontrado. Cadastre o fabricante primeiro.\n");
            continue;
        }

        numProdutos++;

        printf("Produto cadastrado com sucesso!\n");

        char continuar;
        printf("Deseja cadastrar outro produto? (S/N): ");
        scanf(" %c", &continuar);

        if (continuar == 'N' || continuar == 'n')
        {
            break;
        }
    }
    // cadastro dos produtos
    
    //chamada lista e struct:
    listar(produtos);
    ordem (produtos->descricao);
    listar(produtos);

    //menu 

    int opcao;
    do
    {
        printf("\n===== MENU =====\n");
        printf("1 - Listar todas as marcas\n");
        printf("2 - Listar todos os produtos\n");
        printf("3 - Listar produtos por estado\n");
        printf("4 - Listar produtos por marca\n");
        printf("5 - Encontrar estado onde esta registrado o produto mais caro\n");
        printf("6 - Encontrar fabricante onde esta registrado o produto mais barato\n");
        printf("7 - Listar produtos em ordem crescente de valor de venda\n");
        printf("8 - Listar produtos em ordem crescente de valor de lucro\n");
        printf("9 - Listar produtos em ordem crescente de percentual de lucro\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            listarTodasMarcas(fabricantes, numFabricantes);
            break;
        case 2:
            listarTodosProdutos(produtos, numProdutos);
            break;
        case 3:
            listarProdutosPorEstado(produtos, numProdutos);
            break;
        case 4:
            listarProdutosPorMarca(produtos, numProdutos);
            break;
        case 5:
            encontrarEstadoProdutoMaisCaro(produtos, numProdutos);
            break;
        case 6:
            encontrarFabricanteProdutoMaisBarato(produtos, numProdutos);
            break;
        case 7:
            listarProdutosPorValor(produtos, numProdutos);
            break;
        case 8:
            listarProdutosPorLucro(produtos, numProdutos);
            break;
        case 9:
            listarProdutosPorPercentualLucro(produtos, numProdutos);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Digite novamente.\n");
        }
        } while (opcao != 0);
        //menu 
    return 0;
}

char listar(struct Ordem alfabeto[]){
	int i=0;
	for(i=0;i<MAX_PRODUTOS;i++){
		printf("%s\n", produtos[i].descricao);
	}			
}


char ordem(struct Ordem alfabeto[]){
	int i, j;
	char aux[30];
	for(i=0;i<MAX_PRODUTOS;i++){
		for(j=i+1;j<MAX_PRODUTOS;j++){
			if(strcmp(produtos[i].descricao,produtos[j].descricao)>0){
				strcpy(aux, produtos[i].descricao);
		     	strcpy(produtos[i].descricao, produtos[j].descricao);
		    	strcpy(produtos[j].descricao , aux);	
		}
	}			
 }
}

/*void leValidaPeso(float *peso) {
    do {
        printf("Peso (em gramas): ");
        scanf("%f", peso);
        if (*peso < 50 || *peso > 50000) {
            printf("Peso invÃ¡lido. O peso deve estar entre 50g e 50kg.\n");
        }
    } while (*peso < 50 || *peso > 50000);

    *peso /= 1000; // Converte de gramas para quilos
}
*/
/*void le_valida_peso(Produto produtos){
    int len = strlen(produtos[i].medida);
    if (len <= 2) {
        // Verifica se a medida termina com "g" para gramas
        if (produtos.medida[len] == 'g') {
            printf("O usuÃ¡rio digitou em gramas.\n");
           
        }else if (produtos.medida[len] == 'k' && produtos.medida[len - 1] == 'g') {
            printf("O usuÃ¡rio digitou em quilogramas.\n");
           
        }
         return;
}
}*/
