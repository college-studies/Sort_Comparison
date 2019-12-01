#include <stdio.h>

#include "staticList.c"
#include "getValues.c"

int bubbleSort(list *ls);

int main(int agrc, char *argv[])
{
    list ls;
    ls.size = SIZE;
    runList(&ls);

    const char *fileName = argv[1];
    startList(&ls,fileName); 

    bubbleSort(&ls);
    
    printf("Trocas realizadas: %d\n",ls.count);

    return 0;
}

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