#include<stdio.h>

#include "staticList.c"
#include "randomValues.c"

int shellSort(list *ls);

int main()
{
    list ls;

    runList(&ls,10);
    getRandom(&ls);

    printf("\n");
    
    shellSort(&ls);
    return 0;
}


int shellSort(list *ls)
{
    if(ls->array!=NULL)
    {
        int i, j, k, valueAux, gap, count = 0;
        
        for (gap = ls->size/2; gap > 0; gap /=2)
        {
            for (i = gap; i < ls->size; i++)
            {   
                j=i-gap;

                while (j >=0)
                {
                    k=j+gap;
                    
                    if (ls->array[j] < ls->array[k])
                        j --;
                    else
                    {                 
                        valueAux = ls->array[j];
                        ls->array[j] = ls->array[k];
                        ls->array[k] = valueAux;
                        j -= gap;
                        count ++;
                    }

                }
                            
            }
        }
        printf("Numero de trocas = %d\n",count);
    }
    return 0;
}