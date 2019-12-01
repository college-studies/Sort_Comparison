#ifndef randomValues_c
#define randomValues_c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "staticList.c"

#define SIZE 10

int startList(list *ls,const char *fileName)
{
    FILE *file;
    int value, i = 0;

    file = fopen(fileName,"r");
    
    if (file == NULL)
    {
        printf("Opening file error");
        return 0;
    }
    printf("Teste\n");
    while (EOF != fscanf(file, "%d", &value))
    {
        ls->array[i] = value;
        i++;
        
    }
    return 1;   
}

#endif