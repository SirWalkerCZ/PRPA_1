#include <stdlib.h>
#include <stdio.h>
//podobné jako malloc
void vypis_int(int * ptr, int delka){
    for (int* ptr_end= ptr+delka; ptr < ptr_end; ptr++)
    {
        printf("%4i\t", *ptr);
    }
    printf("\n");
}
int main(int argc, char *argv[]) {
    int n = 5;

    //void * calloc(size_t num, size t size) //alokuje pocet prvku dane velikosti a vynuluje je
    int* heapc = NULL;
    heapc = (int*) calloc(sizeof(int), n);
    if (heapc == NULL) //v případě že je pamět plná
    {
        printf("Alokace se nepodařila");
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        heapc[i]= i*i;
    }
    vypis_int(heapc, n);
    
    free(heapc); //uvolní pamět pole

    return 0;
}