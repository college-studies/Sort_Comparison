#ifndef sortFuntions_c
#define sortFuntions_c 

#include<stdio.h>
#include<stdlib.h>

#include "staticList.c"

void shellSort(list *ls)
{
    if(ls->array!=NULL)
    {
        int i, j, k, valueAux, hop, count = 0;
        int flag; 

        hop = (ls->size/2);
        if (hop % 2 == 0)
            hop ++;
        
        while (hop >= 1)
        {
            for (i = 0, j = hop; j < ls->size; i++, j++)
            {
                if (ls->array[i] > ls->array[j])
                {
                    valueAux = ls->array[i];
                    ls->array[i] = ls->array[j];
                    ls->array[j] = valueAux;
                    flag = 1;
                    k = i;
                    count ++;

                    while (flag=1)
                    {
                        flag = 0;
                        if (ls->array[k] < ls->array[k-hop])
                        {
                            valueAux = ls->array[k];
                            ls->array[k] = ls->array[j];
                            ls->array[j] = valueAux;
                            flag = 1;
                            k = k-hop;
                            count ++;
                        }
                    }
                }
                            
            }
            hop = hop/2;
            if (hop % 2 == 0)
                hop ++;
        }
        
    }
}


#endif