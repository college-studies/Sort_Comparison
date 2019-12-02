#ifndef sortFunctions_c
#define sortFunctions_c

#include <stdio.h>
#include <stdlib.h>

#include "staticList.c"
#include "getValues.c"

#include <sys/times.h> 
#include <sys/types.h> 
#include <unistd.h> 

//Prototypes
void selectionSort(list *ls);
void swap(int *xp, int *yp);
#endif


int main(int agrc, char *argv[])
{
    
    clock_t tt;
	struct tms time; 
    int tics_per_second; 

    tics_per_second = sysconf(_SC_CLK_TCK);
    
    list ls;
    int i;
    ls.count = 0;

    ls.size = SIZE;
    runList(&ls);

    const char *fileName = argv[1];
    startList(&ls,fileName); 

    selectionSort(&ls);
    printf("\nNumero de trocas: %d\n",ls.count);
    tt = times(&time);
    printf("\nRUN TIME: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );

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
