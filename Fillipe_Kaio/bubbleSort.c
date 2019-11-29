#include <stdio.h>
#include "staticList.c"
#include "randomValues.c"

int bubbleSort(list *ls);

int main()
{
    list ls;
    int i;
    int j;

    runList(&ls,10);
    getRandom(&ls);
    for(i=0;i<ls.size;i++)
    {
       printf("%d\n",ls.array[i]);
    }

    printf("\n");
    printf("\nTeste\n");
    
    bubbleSort(&ls);
    for(i=0;i<ls.size;i++)
    {
       printf("%d\n",ls.array[i]);
    }    
    

    return 0;
}

int bubbleSort(list *ls)
{
    if(ls->array!=NULL)
    {
        int i, j, valueAux, count = 0;
        for(i = 0; i < ls->size-1; i++)
        {
            for (j = 0; j < ls->size-i-1; j++)
            {
                if (ls->array[j] > ls->array[j+1])
                {
                    valueAux = ls->array[j];
                    ls->array[j] = ls->array[j+1];
                    ls->array[j+1] = valueAux;
                    count++;
                }
            }
        }
        printf("Trocas realizadas: %d\n",count);
    }

    return 0;
}