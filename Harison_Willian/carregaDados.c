#ifndef CARREGADADOS_C
#define CARREGADADOS_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"listaestatica.c"


void carregaDados(tipoLista*);

void carregaDados(tipoLista *lst)
{
	
        
	FILE *arq1000, *arq10000, *arq100000;
	
	arq1000 = fopen( "1000.arq1.txt",  "w");
	
	//         PARA MIL NÚMEROS ALEATORIOS 
	if(arq1000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq1000, "%d", GeraAleatorios(numeros,1000,1000000));	
			
	fclose(arq1000);
	
	arq1000 = fopen( "1000.arq2.txt",  "w");
	
	if(arq1000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq1000, "%d", GeraAleatorios(numeros,1000,1000000));
	
	fclose(arq1000);
	
	arq1000 = fopen( "1000.arq3.txt",  "w");
	
	if(arq1000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq1000, "%d", GeraAleatorios(numeros,1000,1000000));
	
	fclose(arq1000);
	
	arq1000 = fopen( "1000.arq4.txt",  "w");
	
	if(arq1000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq1000, "%d", GeraAleatorios(numeros,1000,1000000));
	
	arq1000 = fopen( "1000.arq5.txt",  "w");
	
	if(arq1000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq1000, "%d", GeraAleatorios(numeros,1000,1000000));
	
	fclose(arq1000);
	
	//		PARA 10 MIL NÚMEROS ALEATÓRIOS 
	
	arq10000 = fopen( "10000.arq1.txt",  "w");
	
	if(arq10000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq10000, "%d", GeraAleatorios(numeros2,10000,1000000));
		
	fclose(arq10000);
	
	arq10000 = fopen( "10000.arq2.txt",  "w");
	
	if(arq10000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq10000, "%d", GeraAleatorios(numeros2,10000,1000000));
		
	fclose(arq10000);
	
	arq10000 = fopen( "10000.arq3.txt",  "w");
	
	if(arq10000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq10000, "%d", GeraAleatorios(numeros2,10000,1000000));
		
	fclose(arq10000);
	
	arq10000 = fopen( "10000.arq4.txt",  "w");
	
	if(arq10000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq10000, "%d", GeraAleatorios(numeros2,10000,1000000));
		
	fclose(arq10000);
	
	arq10000 = fopen( "10000.arq5.txt",  "w");
	
	if(arq10000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq10000, "%d", GeraAleatorios(numeros2,10000,1000000));
		
	fclose(arq10000);
	
	//		PARA 100 MIL NÚMEROS ALEATÓRIOS 
	
	arq100000 = fopen( "100000.arq1.txt",  "w");
	
	if(arq100000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq100000, "%d", GeraAleatorios(numeros3,100000,1000000));
		
	fclose(arq100000);
	
	arq100000 = fopen( "100000.arq2.txt",  "w");
	
	if(arq100000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq100000, "%d", GeraAleatorios(numeros3,100000,1000000));
		
	fclose(arq100000);
	
	arq100000 = fopen( "100000.arq3.txt",  "w");
	
	if(arq100000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq100000, "%d", GeraAleatorios(numeros3,100000,1000000));
		
	fclose(arq100000);
	
	arq100000 = fopen( "100000.arq4.txt",  "w");
	
	if(arq100000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq100000, "%d", GeraAleatorios(numeros3,100000,1000000));
		
	fclose(arq100000);
	
	arq100000 = fopen( "100000.arq5.txt",  "w");
	
	if(arq100000 == NULL)
	{
		printf("ERRO AO ABRIR O ARQUIVO\n");
		return 0;
	}
	else
		fcanf(arq100000, "%d", GeraAleatorios(numeros3,100000,1000000));
		
	fclose(arq100000);
	
	/*	while ( fscanf(arquivoEntrada, "%s", comando) != EOF) 
		{ //Le comando
           		 if ( fscanf(arquivoEntrada, "%d ", &dado) ) 
           		{ //Le dado
                		if ( strcmp(comando, "II") == 0 ) //trata comando insere inicio
                    			insereInicio(lst, dado);
                		else if ( strcmp(comando, "IF") == 0 )  //trata comando insere fim
                    			insereFim(lst, dado);
                		else if ( strcmp(comando, "IP") == 0 ) //trata comando insere posicao
                    		{
                    			fscanf(arquivoEntrada, "%d", &pos); //Le posicao
                    			inserePosicao(lst, dado, pos);
                    		}
               		}
           	}
        }
	*/
}
#endif
