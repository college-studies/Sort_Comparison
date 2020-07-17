#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "staticList.c"
#include "getValues.c"

#include <sys/times.h> 
#include <sys/types.h> 
#include <unistd.h> 

//Prototypes
void insertionSort(list *ls);

int main(int agrc, char *argv[]){
    
    clock_t tt;
	struct tms time; 
    int tics_per_second; 

    tics_per_second = sysconf(_SC_CLK_TCK);
    
    list ls; int i;
    ls.count = 0;
    
    ls.size = SIZE;
    runList(&ls);

    const char *fileName = argv[1];
    startList(&ls,fileName); 

    //Output ordered List 
    insertionSort(&ls);
    
    printf("Numero de trocas: %d\n", ls.count);
    tt = times(&time);
    printf("\nRUN TIME: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );

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
