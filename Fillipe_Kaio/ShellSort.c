#ifndef sortFuntions_c
#define sortFuntions_c 

#include<stdio.h>
#include<stdlib.h>

#include "staticList.c"
#include "randomValues.c"

int shellSort(list *ls);

int main()
{
    list ls;
    int i;

    runList(&ls,1000);
    getRandom(&ls);
    for(i=0;i<ls.size;i++)
    {
       printf("%d\n",ls.array[i]);
    }

    printf("\n");
    printf("\nTeste\n");
    
    shellSort(&ls);
    for(i=0;i<ls.size;i++)
    {
       printf("%d\n",ls.array[i]);
    }    



    return 0;
}


int shellSort(list *ls)
{
    if(ls->array!=NULL)
    {
        int i, j, k, valueAux, hop, count = 0;
        
        for (hop = ls->size/2; hop > 0; hop /=2)
        {
            for (i = hop; i < ls->size; i++)
            {
                valueAux = ls->array[i];

                for (j = i; j >= hop && ls->array[j - hop] > valueAux; j -= hop)
                {
                    ls->array[j] = ls->array[j - hop];
                    count ++;
                }   
                    ls->array[j] = valueAux;

                /*if (ls->array[i] > ls->array[j])
                {
                    
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
                }*/
                            
            }
        }
        
    }
    return 0;
}


#endif