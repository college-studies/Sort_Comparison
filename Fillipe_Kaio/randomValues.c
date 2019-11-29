#ifndef randomValues_c
#define randomValues_c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "staticList.c"

void getRandom(list *ls)
{
    int i=0,j, number, flag;

    srand(time(NULL));

    for (i=0; i < ls->size; i++)
    {
        number = rand()%100;
        flag = 0;

        if (number <= 0)
            number = number * (-1);

        for(j=0; j<i; j++)
        {
            if (ls->array[j]==number)
                flag = 1;
        }

        if(!flag)
            ls->array[i] = number;
        else
            i--;
    }
}


#endif