#ifndef ORDENACAO_C
#define ORDENACAO_C

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"listaestatica.c"

//void bubbleSort(tipoLista *lst);
//void shellSort(tipoLista *lst, int tamanho);
void merge_sort(tipoLista *lst, int tamanho);
void merge(tipoLista *lst, int tamanho);
//void insertSort(tipoLista *lst);
//void quickSort(tipoLista *lst);
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

	if(listaVazia(*lst))
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
}
*/
void merge_sort(tipoLista *lst, int tamanho){
	int meio;
	if(tamanho > 1){
		meio = tamanho / 2;
		merge_sort(lst, meio);
		merge_sort(&lst[meio], (tamanho-meio));
		merge(lst, tamanho);
	}
}

void merge(tipoLista *lst, int tamanho){
	int *vetAux;
	vetAux = (int*)malloc(sizeof(int) * tamanho);
	int i, j, meio, posVetAux;
	
	meio = j = tamanho / 2;
	i = 0;
	posVetAux = 0;
	lst->tras++;
	while((i < meio) && (j < tamanho)){
		lst->tras++;
		if(lst->vet[i] < lst->vet[j]){
			vetAux[posVetAux] = lst->vet[i];
			i++;
		}else{
			vetAux[posVetAux] = lst->vet[j];
			j++;
		}
		posVetAux++;
	}
	lst->tras++;
	while(i < meio){
		vetAux[posVetAux] = lst->vet[i];
		posVetAux++;
		i++;
	}
	while(j < tamanho){
		vetAux[posVetAux] = lst->vet[j];
		posVetAux++;
		j++;
	}
	for(i = 0; i < tamanho; i++){
		lst->vet[i] = vetAux[i];
	}
	free(vetAux);
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
}
void quickSort(tipoLista *lst, int ini, int fim)
{
	int i, f, meio, pivo, aux;
	if(listaVazia(lst))
		printf("LISTA VAZIA\n");
	else
	{
		meio = (ini + fim)/2;
		pivo = lst->vet[meio];
	
		i = ini;
		f = fim;
	
		while (i < f)
		{
			while ( lst->vet[i] < pivo )
				i++;
			while ( lst->vet[f] > pivo )
				f--;
			
			if( i < f)
			{
				aux = lst->vet[i];
				lst->vet[i] = lst->vet[f];
				lst->vet[f] = aux;
			}
			
			if( f > inicio)
				quickSort(lst, inicio, f);
			
			if( i < fim)
				quickSorte(lst, i, fim);
		}
	}
}
void selectionSort(tipoLista *lst)
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