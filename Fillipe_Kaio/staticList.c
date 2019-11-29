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



int runList(list *ls,int size){
    ls->size=size;
    ls->array = (int *) malloc(sizeof(int)*ls->size);

    return 0;
}

#endif