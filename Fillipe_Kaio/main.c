#ifndef randomValues_c
#define randomValues_c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 999999

int main()
{
    int i=0,j,k, number, flag,qtt;
    char name[15];
    FILE *file;

    printf("Quantity per file: ");
    scanf("%d", &qtt);

    for(k = 1 ; k <= 5 ; k++)
    {
        int aux[qtt];
        sprintf(name, "%d-arq%d.txt",qtt,k);
        file = fopen(name, "w");

        if(file == NULL)
        {
            printf("Opening file error");
            return 0;
        }

        srand( (unsigned) k + i * time(NULL));

        for (i=0; i < qtt; i++)
        {
            number = rand() % MAX;
            flag = 0;

            for(j=0; j<i; j++)
            {
                if (aux[j]==number)
                    flag = 1;
            }

            if(!flag)
            {
                aux[i] = number;
                fprintf(file, "%d\n", number);
            }
            else
                i--;
        }
        fclose(file);
    }
}


#endif