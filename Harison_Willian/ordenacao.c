#ifndef ORDENACAO_C
#define ORDENACAO_C

#include<stdio.h>
#include<stdlib.h>

#include"listaestatica.c"

//void bubbleSort(tipoLista *lst);
//void shellSort(tipoLista *lst, int tamanho);
//void mergeSort(tipoLista *lst, int tamanho);
//void insertSort(tipoLista *lst);
int dividir(tipoLista *lst, int esq, int dir);
void quickSort(tipoLista *lst, int esq, int dir);
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
/*void mergeSort(tipoLista *lst, int tamanho)
{
	int i, meio, dir, esq, aux[tamanho], k;

	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		for(i=0; i < lst->tam; i++)
			aux[i]=lst->vet[i];
	
		esq = 0;
		meio = tamanho/2;
		dir = meio+1;
		k = 0;
	
		while(esq <= meio && dir<=tamanho)
		{
			if(aux[esq] < aux[dir])
			{
				lst->vet[k] = aux[esq];
				esq++;
			}
			else
			{
				lst->vet[k] = aux[dir];
				dir++;
			}
			k++;
		}
		while(esq <= meio)
		{
			lst->vet[k] = aux[esq];
			k++;
			esq++;
		}
	}
}*/
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
int dividir(tipoLista *lst, int esq, int dir)
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
			
}
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
