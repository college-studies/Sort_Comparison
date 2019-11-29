#ifndef sortFunctions_c
#define sortFunctions_c

#include <stdlib.h>
#include <stdio.h>

#include "staticList.c"
#include "randomValues.c"

//Prototypes
void swap(int* a, int* b);
int partition(list *ls, int low, int high);
void quickSort(list *ls, int low, int high);

#endif

//Swapping elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*Recursive Function that takes last element as pivot and places the pivot 
on its corrent position in sorted array, and places all smaler than pivot 
to left of pivot and greaters to the right */
int partition(list *ls, int low, int high)
{
    int pivot = ls->array[high]; //pivot
    int i = (low - 1); //Smaller element index

    for ( int j = low; j <= high; j++)
    {
        //If current element is smaller than pivot
        if (ls->array[j] < pivot)
        {
            i++; //increment index of smaller element
            swap(&ls->array[i], &ls->array[j]);
        }
    }
    swap(&ls->array[i+1],&ls->array[high]);
    return (i+1);
}

void quickSort(list *ls, int low, int high)
{
    //low = starting index & high = ending index
    if (low < high){
        // pi as partitioning index, arr[p] is in the right place   
        int pi = partition (ls->array,low,high);

        //Separately sort elements before and after partition
        quickSort(ls->array, low, pi - 1);
        quickSort(ls->array, pi + 1, high);
    }
}


