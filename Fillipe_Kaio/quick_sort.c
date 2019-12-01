#ifndef sortFunctions_c
#define sortFunctions_c

#include <stdlib.h>
#include <stdio.h>

#include "staticList.c"
#include "getValues.c"

//Prototypes
int partition(list *ls, int low, int high);
void quickSort(list *ls, int low, int high);

int main(int agrc, char *argv[])
{
    list ls;
    int i;
    ls.count = 0;

    ls.size = SIZE;
    runList(&ls);

    const char *fileName = argv[1];
    startList(&ls,fileName); 

    for(i=0;i<ls.size;i++)
    {
       printf("%d\n",ls.array[i]);
    }

    printf("\n");

    quickSort(&ls,0,ls.size);
    printf("\nNumero de trocas: %d\n",ls.count);
    for(i=0;i<ls.size;i++)
    {
       printf("%d\n",ls.array[i]);
    }    



    return 0;
}


/*Recursive Function that takes last element as pivot and places the pivot 
on its corrent position in sorted array, and places all smaler than pivot 
to left of pivot and greaters to the right */
int partition(list *ls, int low, int high)
{
    int pivot = ls->array[low]; //pivot
    int i,aux,j;
    i = low;
    for ( j = low+1; j <= high; j++)
    {
        //If current element is smaller than pivot
        if (ls->array[j] < pivot)
        {
            i++; //increment index of smaller element
            aux = ls->array[j];
            ls->array[j] = ls->array[i];
            ls->array[i] = aux;
            ls->count++;
        }
    }
	aux = ls->array[low];
	ls->array[low] = ls->array[i];
	ls->array[i] = aux;
	
	return i;
}

void quickSort(list *ls, int low, int high)
{
    //low = starting index & high = ending index
    if (low < high){
        // pi as partitioning index, arr[p] is in the right place   
        int pi = partition (ls,low,high);

        //Separately sort elements before and after partition
        quickSort(ls, low, pi - 1);
        quickSort(ls, pi + 1, high);
    }
}

#endif
