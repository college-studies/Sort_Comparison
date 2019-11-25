#ifndef ORDENACAO_C
#define ORDENACAO_C

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"listaestatica.c"

//void bubbleSort(tipoLista *lst);
//void shellSort(tipoLista *lst, int tamanho);
void mergeSort(tipoLista *lst, int inicio, int fim);
void merge(tipoLista *lst, int inicio, int meio, int fim);
//void insertSort(tipoLista *lst);
//int dividir(tipoLista *lst, int esq, int dir);
//void quickSort(tipoLista *lst, int esq, int dir);
//void selectionSort(tipoLista *ls);

/*void bubbleSort(tipoLista *lst)
{
	int i, contador, aux;
	
	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		for(contador=1; contador <= lst->tras; contador++)
		{
			for(i=0; i <= lst->tras-1; i++)
			{
				if(lst->vet[i] > lst->vet[i+1])
				{
					aux=lst->vet[i];
					lst->vet[i]=lst->vet[i+1];
					lst->vet[i+1]=aux;
				}
			}
		}
	}
}
*/
/*void shellSort(tipoLista *lst, int tam)
{
	int i, salto, frente, tras, aux;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		salto = tam/2;
	
		while(salto > 0 )
		{
			for(i=salto; i < lst->tam; i++)
			{
				tras= i-salto;
				
				while( tras >= 0)
				{
					frente= tras+salto;
					
					if(lst->vet[tras] < lst->vet[frente])
						tras= -1;
					else
					{
						aux = lst->vet[tras];
						lst->vet[tras] = lst->vet[frente];
						lst->vet[frente] = aux;
						tras = tras - salto;
 					}
 				}
 			}
 			salto = salto/2;
 		}
	}
}*/
void mergeSort(tipoLista *lst, int inicio, int fim)
{
	int meio, troca;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		if(inicio < fim)
		{
			meio = floor( (inicio+fim)/2 );
			mergeSort(lst, inicio, meio);
			mergeSort(lst, meio+1, fim);
			merge(lst, inicio, meio, fim);
		}
	}
}
void merge(tipoLista *lst, int inicio, int meio, int fim)
{
	int *temp, p1, p2, tamanho, i , j, k;
	int fim1=0, fim2=0, cont=1;
	
	tamanho = fim-inicio+1;
	
	p1 = inicio;
	p2 = meio+1;
	
	temp = (int*) malloc(tamanho*sizeof(int));
	
	if(temp != NULL)
	{
		for(i=0; i < tamanho; i++)
		{
			if(!fim1 && !fim2)
			{
				if(lst->vet[p1] < lst->vet[p2])
				{
					temp[i] = lst->vet[p1++];
					cont++;
				}
				else
				{
					temp[i] = lst->vet[p2++];
					cont++;
				}
				if(p1 > meio)
					fim1 = 1;
				if(p2 > fim)
					fim2 = 1;
			}
			else
			{
				if(!fim1)
					temp[i] = lst->vet[p1++];
				else
					temp[i] = lst->vet[p2++];
			}
		}
		for(j=0, k = inicio; j < tamanho; j++, k++)
			lst->vet[k] = temp[j];
	}
	printf("QUANTIDADE DE TROCAS: %d\n", cont);
	free(temp);
}		
/*void insertSort(tipoLista *lst)
{
	int i, j, aux;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		for(i=1; i < lst->tam; i++)
		{
			aux = lst->vet[i];
			j = i-1;
			
			while ( (j>= 0) && (aux < lst->vet[j]) )
			{
				lst->vet[j+1] = lst->vet[j];
				j--;
			}
			
			lst->vet[j+1] = aux;
		}
	}
}*/
/*int dividir(tipoLista *lst, int esq, int dir)
{
	int aux, i, cont=esq;
	
	for(i=esq+1; i <= dir; i++)
	{
		if(lst->vet[i] < lst->vet[esq])
		{
			cont++;
			aux = lst->vet[i];
			lst->vet[i] = lst->vet[cont];
			lst->vet[cont] = aux;
		}
		
	}
	
	aux = lst->vet[esq];
	lst->vet[esq] = lst->vet[cont];
	lst->vet[cont] = aux;
	
	return cont;
}			
void quickSort(tipoLista *lst, int esq, int dir)
{
	int pos;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		if(esq < dir)
		{
			pos = dividir(lst, esq, dir);
			quickSort(lst, esq, pos-1);
			quickSort(lst, pos+1, dir);
		}
	}
			
}*/
/*void selectionSort(tipoLista *lst)
{
	int menor,aux, i, j;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		for(i=0; i < lst->tam ;i++)
		{
			menor = i;
			for(j=i+1; j < lst->tam;j++)
			{
				if(lst->vet[menor]>lst->vet[j])
					menor=j;
			}
			if(i!=menor)
			{
				aux=lst->vet[i];
				lst->vet[i]=lst->vet[menor];
				lst->vet[menor]=aux;
			}
		}
	}
}*/
#endif
