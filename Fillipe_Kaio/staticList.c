#ifndef staticList_c
#define staticList_c

#include<stdlib.h>
#include<stdio.h>


typedef struct staticList
{
    int *array;
    int size;
} list;

int runList(list *ls, int size);

int main()
{
    list ls;    
    int i;
    
    runList(&ls,20);
    for(i=0;i<ls.size;i++){
       printf("%d\n",ls.array[i]);
    } 

    free(ls.array);

    printf("\n");
    runList(&ls,10);
    for(i=0;i<ls.size;i++){
       printf("%d\n",ls.array[i]);
    } 
    return 0;
}

int runList(list *ls,int size){
    int i;
    ls->size=size;
    ls->array = (int *) malloc(sizeof(int)*ls->size);
    if(ls->array != NULL){
        for(i=0; i<ls->size; i++){
            ls->array[i]=i;
        }
    }

    return 0;
}

#endif