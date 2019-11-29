#ifndef sortFunctions_c
#define sortFunctions_c

#include <stdio.h>
#include <stdlib.h>

#include "staticList.c"
#include "randomValues.c"

//Prototypes
void selectionSort(list *ls);
void swap(int *xp, int *yp);
#endif

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
        ls->cont += 1;
    }


}

//Swapping Function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*--------------------------------------------------------------------*/

int main(){
    
    list ls; int i;
    ls.cont = 0;

    runList(&ls,10);
    getRandom(&ls);
    //Output Unordered List
    for ( i = 0; i < ls.size; i++)
       printf("%d\n",ls.array[i]);
    
    printf("\n");
    printf("\nTeste\n");

    //Output ordered List 
    selectionSort(&ls);
    for ( i = 0; i < ls.size; i++)
        printf("%d\n",ls.array[i]);

    return 0;
}
