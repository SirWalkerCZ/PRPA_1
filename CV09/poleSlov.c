#include "stdlib.h"
#include <stdio.h>
void vypis_char(char *ptr, int delka)
{
    for (int *ptr_end = ptr + delka; ptr < ptr_end; ptr++)
    {
        printf("%4i\t", *ptr);
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    int N = 32;
    int kam = 0;
    char *heapm = NULL;
    heapm = (char *)malloc(N * sizeof(char));
    while (scanf("%c", kam) > 0)
    {
        kam++; // vždycky když načteme, pointr posunu o jedna
        if (kam >= N)
        {
            N += 32; // pokusíme se zvětšit alokované pole
            char *tmp_ptr = (char *)realloc(N * sizeof(char));
            if (tmp_ptr == NULL) //nepodařilo se alokovat
            {
                free(heapm); //uvolníme pamět protože končíme
                printf("Nepodarilo se alokovat");
                return -1;
            }
            else{
                heapm = tmp_ptr;
            }
        }
    }
}