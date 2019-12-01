#ifndef sortFunctions_c
#define sortFunctions_c

#include <stdio.h>
#include <stdlib.h>

#include "staticList.c"
#include "getValues.c"

//Prototypes
void selectionSort(list *ls);
void swap(int *xp, int *yp);
#endif


int main(int agrc, char *argv[])
{
    list ls;
    int i;
    ls.count = 0;

    ls.size = SIZE;
    runList(&ls);

    const char *fileName = argv[1];
    startList(&ls,fileName); 

    //Output Unordered List
    for ( i = 0; i < ls.size; i++)
       printf("%d\n",ls.array[i]);
    
    printf("\n");
    printf("\nTeste\n");

    //Output ordered List 
    selectionSort(&ls);
    printf("\nNumero de trocas: %d\n",ls.count);
    for ( i = 0; i < ls.size; i++)
        printf("%d\n",ls.array[i]);

    return 0;
}

/*--------------------------------------------------------------------*/

//SELECTION SORT FUNCTION
void selectionSort(list *ls)
{
    int i,j, min_pst;
    
    for ( i = 0; i < ls->size; i++) // 
    {
        //Searching for the minimum unsorted element
        min_pst = i;
        for ( j = i+1 ; j < ls->size; j++)
        if (ls->array[j] < ls->array[min_pst] )
            min_pst = j;
        
        //Swapping the minimum unsorted with the [] element
        swap(&ls->array[min_pst], &ls->array[i]);
        ls->count += 1;
    }


}

//Swapping Function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}