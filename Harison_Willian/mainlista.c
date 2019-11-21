#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//inclusão de biblioteca proprias
#include"listaestatica.c"
#include"carregaDados.c"
#include"ordenacao.c"
#include"numeros.c"
	
int main(int argc, char *argv[])
{
	tipoLista lista;
	int numeros[1000], numeros2[10000], numeros3[100000];
	
	/*if( argc !=2 )
	{
		printf("FALHA NA QUANTIDADE DE ARGUMENTOS\n");
		return 0;
	}*/
	
	// FUNÇÃO PARA GERAR NUMEROS ALEATÓTIOS 
	
	
	
	inicializaLista(&lista);//inicializando a Lista
	
	
	printf("\nimprimindo a lista\n");
	
	imprime(&lista);
	
	printf("\n");

	bubbleSort(&lista);
	
	printf("\nIMPRIMINDO LISTA ORDENADA\n");
	
	imprime(&lista);
	
	printf("\n");
	
	
	return 1;
}	
