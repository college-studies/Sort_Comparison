#include <stdio.h>

#include "staticList.c"
#include "getValues.c"

#include <sys/times.h> 
#include <sys/types.h> 
#include <unistd.h> 

int bubbleSort(list *ls);

int main(int agrc, char *argv[])
{
    
    clock_t tt;
	struct tms time; 
    int tics_per_second; 

    tics_per_second = sysconf(_SC_CLK_TCK);
    
    list ls;
    ls.size = SIZE;
    runList(&ls);

    const char *fileName = argv[1];
    startList(&ls,fileName); 

    bubbleSort(&ls);
    
    printf("Trocas realizadas: %d\n",ls.count);
    tt = times(&time);
    printf("\nRUN TIME: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );

    return 0;
}
//
int bubbleSort(list *ls)
{
    if(ls->array!=NULL)
    {
        int i, j, valueAux;
        for(i = 0; i < ls->size-1; i++)
        {
            for (j = 0; j < ls->size-i-1; j++)
            {
                if (ls->array[j] > ls->array[j+1])
                {
                    valueAux = ls->array[j];
                    ls->array[j] = ls->array[j+1];
                    ls->array[j+1] = valueAux;
                    ls->count++;
                }
            }
        }
    }

    return 0;
}
