#ifndef sortFunctions_c
#define sortFunctions_c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "staticList.c"
#include "randomValues.c"

//Prototypes
void insertionSort(list *ls);
#endif

void insertionSort(list *ls)
{
    int i,key,j;
    for ( i = 1; i < ls->size; i++)
    {
        key = ls->array[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && ls->array[j] > key)
        {
            ls->array[j+1] = ls->array[j];
            j = j - 1;
        }
        ls->array[j+1] = key;
    }
}

int main(){
    
    list ls; int i;

    runList(&ls,10);
    getRandom(&ls);
    //Output Unordered List
    for ( i = 0; i < ls.size; i++)
       printf("%d\n",ls.array[i]);
    
    printf("\n");
    printf("\nTeste\n");

    //Output ordered List 
    insertionSort(&ls);
    for ( i = 0; i < ls.size; i++)
        printf("%d\n",ls.array[i]);

    return 0;
}
