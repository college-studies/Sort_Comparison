#ifndef staticList_c
#define staticList_c

#include<stdlib.h>
#include<stdio.h>


typedef struct staticList
{
    int *array;
    int size;
    int count;
} list;



int runList(list *ls)
{
    ls->array = (int *) malloc(sizeof(int)*ls->size);

    return 1;
}

#endif