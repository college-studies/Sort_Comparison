#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "staticList.c"
#include "getValues.c"

//Prototypes
void insertionSort(list *ls);

int main(int agrc, char *argv[]){
    
    list ls; int i;
    ls.count = 0;
    
    ls.size = SIZE;
    runList(&ls);

    const char *fileName = argv[1];
    startList(&ls,fileName); 

    //Output ordered List 
    insertionSort(&ls);
    
    printf("Numero de trocas: %d\n", ls.count);

    return 0;
}

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
        ls->count += 1;
    }
}
