#include <stdlib.h>
#include <stdio.h>

void vypis_int(int * ptr, int delka){
    for (int* ptr_end= ptr+delka; ptr < ptr_end; ptr++)
    {
        printf("%4i\t", *ptr);
    }
    printf("\n");
}
int main(int argc, char *argv[]) {
    int n = 5;

    //void * malloc( size t size) //alokuje dany pocet bytu
    int* heapm = NULL;
    heapm = (int*) malloc(n * sizeof(int));
    if (heapm == NULL) //v případě že je pamět plná
    {
        printf("Alokace se nepodařila");
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        heapm[i]= i*i;
    }
    vypis_int(heapm, n);
    
    free(heapm); //uvolní pamět pole

    return 0;
}