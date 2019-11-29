#include<stdio.h>

#include "staticList.c"
#include "randomValues.c"

int merge(list *ls, int f, int middle, int b);
int mergeSort(list *ls, int f, int b);

int main()
{
    list ls;
    ls.cont = 0;
    int i,j;

    runList(&ls, 10);

    for (i=0,j=9;i<10;i++,j--)
    {
        ls.array[i] = j;
        printf("%d\n", ls.array[i]);
    }

    ls.cont = mergeSort(&ls, 0, ls.size);
    printf("Teste\n");
    
    for (i=0;i<10;i++)
    {
        printf("%d\n",ls.array[i]);
    }

    return 0;
}

int mergeSort (list *ls, int f,int b)
{
    int middle, count = 0;
    if (b > f)
    {
        middle = ( (f + b)/2 );
        if (middle<0)
            middle *=(-1); 
    
        mergeSort(ls, f, middle);
        mergeSort(ls, middle + 1, b);
        count += merge(ls, f, middle, b);
    }
    return count;
}

int merge(list *ls, int f, int middle, int b)
{
    int *temp, aux1, aux2, size, i, j, k;
    int b1 = 0, b2 = 0, count = 0; 
    
    size = b - f + 1;
    aux1 = f;
    aux2 = middle+1;

    temp = (int*) malloc (sizeof(int)*size);

    if(temp != NULL)
    {
        for(i = 0; i < size; i++)
        {
            if (!b1 && !b2)
            {
                if(ls->array[aux1] < ls->array[aux2])
                {
                    temp[i] = ls->array[aux1++];
                }
                else
                {
                    temp[i] = ls->array[aux2++];
                }
                if(aux1 > middle)
                    b1 = 1;
                if(aux2 > b)
                    b2 = 1;
            }
            else
            {
                if(!b1)
                {
                    temp[i] = ls->array[aux1++];
                }
                else
                {
                    temp[i] = ls->array[aux2++];
                }
            }      
        }
        for(j=0, k = f; j < size; j++, k++)
			ls->array[k] = temp[j];
    }
    free(temp);
    return count;
}